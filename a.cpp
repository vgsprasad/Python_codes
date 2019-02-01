// -----------------------------------------------------------------------
// VIRTIUM TECHNOLOGY, INC. SOFTWARE LICENSE AGREEMENT
//
// NOTICE: READ THIS SOFTWARE LICENSE AGREEMENT ("AGREEMENT") CAREFULLY. IT CONTAINS RESTRICTIONS, DISCLAIMERS AND LEGAL OBLIGATIONS TO WHICH THE LICENSEE ("YOU") AGREES BY DOWNLOADING AND OR OTHERWISE USING THE SOFTWARE AND ANY RELATED MATERIALS ("SOFTWARE") IN WHATEVER FORM THEY MAY BE TRANSMITTED.
//
// IF YOU DO NOT AGREE WITH ONE OR MORE OF THE TERMS IN THIS AGREEMENT, DO NOT DOWNLOAD THE SOFTWARE AND CONTACT YOUR VIRTIUM REPRESENTATIVE.
//
// YOU WILL BE BOUND BY THE TERMS OF THIS AGREEMENT IF YOU DOWNLOAD THE SOFTWARE.
//
// 1. LICENSE:
// (a) Virtium grants to you a nontransferable, nonexclusive license to use and make one (1) backup copy of the Software subject to the terms and limitations of this Agreement. Your limited right to use the Software does not include the right to modify, adapt, decompile, reverse engineer, or otherwise translate or transfer the Software in whole or in part. You may not use, copy, modify or transfer the Software in contravention of any part of this Agreement.
// (b) THE SOFTWARE IS LICENSED TO YOU BUT NOT SOLD. NO EXPRESS OR IMPLIED TRANSFER OF OWNERSHIP OF ANY KIND OR DEGREE IS INTENDED OR EFFECTUATED BY THIS AGREEMENT. The Software (including any and all associated proprietary rights) is at the time you receive it, and at all times during your use, the sole and exclusive property of Virtium.
//
// 2. TERMINATION.
// This Agreement is effective from the date on which you download the Software. You may terminate this Agreement at any time by destroying the Software and all copies and all information related to Software in any form. It will also terminate automatically and without notice to you if you fail to comply with any term or condition of, or exceed the rights granted by, this Agreement.
//
// 3. DUTY TO PROTECT.
// (a) You agree to use your best efforts and to take all reasonable steps to safeguard the Software to ensure that no unauthorized person shall have access thereto and that no unauthorized copy or disclosure, by any method in any form, in whole or in part, shall be transferred or made.
// (b) You shall maintain all copyright or other proprietary notices on all copies of the Software in any form, in whole or in part.
//
// 4. WARRANTY DISCLAIMER.
// (a) THE SOFTWARE IS LICENSED "AS IS." VIRTIUM MAKES NO WARRANTY OR REPRESENTATION WITH RESPECT TO THE LICENSED MATERIALS, EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, AND ANY STATEMENTS OR REPRESENTATIONS MADE BY ANY OTHER PERSON OR FIRM ARE VOID.
// (b) YOU AGREE NOT TO USE THE LICENSED SOFTWARE IN ANY SITUATION WHERE SIGNFICANT DAMAGE OR INJURY TO PERSONS, PROPERTY OR BUSINESS COULD OCCUR FROM A SOFTWARE ERROR.
// (c) YOU ASSUME ALL RISK AS TO THE SELECTION, USE, PERFORMANCE AND QUALITY OF THE LICENSED MATERIALS. IN NO EVENT WILL VIRTIUM BE LIABLE FOR SPECIAL, DIRECT, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING, BUT NOT LIMITED TO, LOSS OF PROFITS OR INABILITY TO USE THE SOFTWARE.
// (d) Some states and or countries do not allow the exclusion or limitation of incidental or consequential damages, so the above limitation and exclusion may not apply to you.
// (e) UNDER NO CIRCUMSTANCES WILL VIRTIUM'S LIABILITY FOR ANY DAMAGES OR LOSS TO YOU OR ANY OTHER PARTY EXCEED THE COST TO REPLACE THE SOFTWARE ITSELF.
//
// 5. SEVERABILITY.
// The provisions of this Agreement are severable and should any provision or portion of a provision be deemed invalid, then only that provision or part thereof shall fail and the remainder of this Agreement shall be in full force and effect.
//
// 6. CHOICE OF LAW.
// This agreement is governed by and construed in accordance with the laws of the State of California. Any suit brought with respect to this Agreement shall be brought only in the state courts of Orange County, California, or in the federal courts situated in the Central District of California.
//
// 7. ENTIRE AGREEMENT.
// This Agreement constitutes the entire agreement between the parties with respect to the same subject matter, and all prior agreements, representations, statements and undertakings are hereby expressly cancelled.
// -----------------------------------------------------------------------

// -----------------------------------------------------------------------
// This program upgrade firmwares
//
// Usage:
//   upgrade config.txt devicepath
//
//   upgrade: name of program
//   config.txt: config file from Virtium
//   devicepath: path to device in Linux system (/dev/hda, ...)
//
// Detail of implementation
//   Read model/version from device under devicepath
//   Read model/binary/version/checksum list from config file
//   Verify md5 checksum of binary file
//   Upgrade matched firmware
//
// Requirement:
//   hdparm tool should be installed before running this program
// -----------------------------------------------------------------------

#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <iomanip>

#include <memory.h>

using namespace std;

// -----------------------------------------------------------------------
// MD5 utility
// -----------------------------------------------------------------------

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

class MD5
{
public:
    const static U32 BLOCK_SIZE = 64;

	enum eMD5SConst {
		MD5_S11 = 7 , MD5_S12 = 12, MD5_S13 = 17, MD5_S14 = 22,
		MD5_S21 = 5 , MD5_S22 = 9 , MD5_S23 = 14, MD5_S24 = 20,
		MD5_S31 = 4 , MD5_S32 = 11, MD5_S33 = 16, MD5_S34 = 23,
		MD5_S41 = 6 , MD5_S42 = 10, MD5_S43 = 15, MD5_S44 = 21, };
    
public:
    MD5();
    MD5(const std::string& text);
    
public:
    void update(const string& filename);
    void update(const U8 *buf, U32 length);
    void finalize();

    string toHexString() const;
    bool getDigestBuffer(U8* buffer) const;

private:
    void init();
    void transform(const U8 block[BLOCK_SIZE]); // Apply MD5 algorithm on a block

private:
    bool IsFinalized;
    U8 Buffer[BLOCK_SIZE]; // bytes that didn't fit in last 64 byte chunk
    U8 Digest[16];         // the result
    U32 State[4];          // digest
    U32 BitCount[2];       // 64bit counter for number of bits (lo, hi)
	
private: // low level logic operations
    static U32 F(U32 x, U32 y, U32 z);
    static U32 G(U32 x, U32 y, U32 z);
    static U32 H(U32 x, U32 y, U32 z);
    static U32 I(U32 x, U32 y, U32 z);
    static U32 rotate_left(U32 x, int n);
    static void FF(U32 &a, U32 b, U32 c, U32 d, U32 x, U32 s, U32 ac);
    static void GG(U32 &a, U32 b, U32 c, U32 d, U32 x, U32 s, U32 ac);
    static void HH(U32 &a, U32 b, U32 c, U32 d, U32 x, U32 s, U32 ac);
    static void II(U32 &a, U32 b, U32 c, U32 d, U32 x, U32 s, U32 ac);
    static void Decode(U32 output[], const U8 input[], U32 len);
    static void Encode(U8 output[], const U32 input[], U32 len);
};

// -----------------------------------------------------------------------
// Common data structure
// -----------------------------------------------------------------------

struct sIdentifyInfo
{
    string DeviceModel;
    string SerialNumber;
    string FirmwareVersion;
};

struct sFirmwareInfo
{
    string DeviceModel;
    string FirmwareVersion;
    string FirmwareFile;
    string FirmwareCode;
    vector<string> CompatibleList;
};

struct sConfigInfo
{
    vector<sFirmwareInfo> Config;
    string TransferMode;
};

// -----------------------------------------------------------------------
// Declare utility functions
// -----------------------------------------------------------------------

// Checking firmware versions
bool ReadIdentifyInfo(const string& devPath, sIdentifyInfo& info);
bool ReadConfigInfo(const string& configPath, sConfigInfo& info);
bool SearchCompatibleFirmware(const sConfigInfo& config, const sIdentifyInfo& info, string& binaryFile, string& checksum);
bool VerifyChecksum(const string firmwareFile, const string& firmwareCode);

// Utility functions for handling text files
void ReadTextFile(const string& fileName, string& text);
bool ReadValue(const string& text, const string& key, string& value);
bool ReadConfigValue(const string& text, const string& key, string& value);
void SplitString(const string& text, char delim, vector<string>& tokenList);

// -----------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "[Usage] " << argv[0] << " configfile devicepath" << endl;
        return 1;
    }

    string configPath = string(argv[1]);
    string devicePath = string(argv[2]);
    
    sIdentifyInfo info;
    if (false == ReadIdentifyInfo(devicePath, info))
    {
        cout << "Cannot identify device under " << devicePath << endl;
        return 1;
    }
    
    sConfigInfo config;
    if (false == ReadConfigInfo(configPath, config))
    {
        cout << "Invalid config file " << configPath << endl;
        return 1;
    }

    cout << "Identify information on device " << devicePath << endl
         << "  Device Model    : " << info.DeviceModel << endl
         << "  Firmware Version: " << info.FirmwareVersion << endl;

    string logFile = "upgradeFwLog.txt";
    string firmwareFile, firmwareCode;
    if (true == SearchCompatibleFirmware(config, info, firmwareFile, firmwareCode))
    {
        if (true == VerifyChecksum(firmwareFile, firmwareCode))
        {
            // Build hdparm command
            stringstream hdparmCmd;
            hdparmCmd << "hdparm --yes-i-know-what-i-am-doing --please-destroy-my-drive --fwdownload"
                      << config.TransferMode << " " <<  firmwareFile << " " << devicePath << " > " << logFile;

            cout << "Execute hdparm command: " << endl;
            cout << hdparmCmd.str() << endl;
            system(hdparmCmd.str().c_str());

            // Print log from hdparm
            string logData;
            ReadTextFile(logFile, logData);
            cout << logData << endl;
        }
        else
        {
            cout << "Wrong MD5 checksum on firmware file " << firmwareFile << endl;
        }
    }
    else
    {
        cout << "No compatible firmware found" << endl;
    }
    
    return 0;
}

// -----------------------------------------------------------------------
// Checking firmware versions
// -----------------------------------------------------------------------

bool ReadIdentifyInfo(const string& devPath, sIdentifyInfo& info)
{
    // This function read identify information from device under devPath
    // Call system tool hdparm
    // hdparm -I /dev/sda
    
    string logFile = "deviceLog.txt";

    // Execute hdparm command
    stringstream sstr;
    sstr << "hdparm -I " << devPath << " > " << logFile;
    
    system(sstr.str().c_str());
    
    // Read identify information from log file
    string logData;
    ReadTextFile(logFile, logData);
    if (false == ReadValue(logData, "Model Number:", info.DeviceModel)) return false;
    if (false == ReadValue(logData, "Serial Number:", info.SerialNumber)) return false;
    if (false == ReadValue(logData, "Firmware Revision:", info.FirmwareVersion)) return false;
    
    return true;
}

bool ReadConfigInfo(const string& configFile, sConfigInfo& info)
{
    info.Config.clear();
    
    // This function read configuration information from input log file
    string configData;
    ReadTextFile(configFile, configData);
    
    // Scan firmware information in config file
    // The firmware number must be sequential from 0 (FW00, FW01, FW02, ...)

    int fwNumber = 0;
    do {
        stringstream fwNumberStr;
        fwNumberStr << setfill('0') << setw(2) << fwNumber;
        
        sFirmwareInfo fwInfo;
        string fwVersionList;
        string keyword;
        
        keyword = "CONFIG_FW" + fwNumberStr.str() + "_MODEL";
        if (false == ReadConfigValue(configData, keyword, fwInfo.DeviceModel)) break;
        
        keyword = "CONFIG_FW" + fwNumberStr.str() + "_VERSION";
        if (false == ReadConfigValue(configData, keyword, fwInfo.FirmwareVersion)) break;
        
        keyword = "CONFIG_FW" + fwNumberStr.str() + "_FILENAME";
        if (false == ReadConfigValue(configData, keyword, fwInfo.FirmwareFile)) break;

        keyword = "CONFIG_FW" + fwNumberStr.str() + "_MD5";
        if (false == ReadConfigValue(configData, keyword, fwInfo.FirmwareCode)) break;

        keyword = "CONFIG_FW" + fwNumberStr.str() + "_COMPATIBLE";
        if (false == ReadConfigValue(configData, keyword, fwVersionList)) break;
        SplitString(fwVersionList, ';', fwInfo.CompatibleList);

        info.Config.push_back(fwInfo);

        ++ fwNumber;
    } while(1);
    
    info.TransferMode = "";
    string transferMode;
    if (true == ReadConfigValue(configData, "CONFIG_TRANSFER_MODE", transferMode))
    {
        std::transform(transferMode.begin(), transferMode.end(), transferMode.begin(), ::tolower);
        info.TransferMode = "-" + transferMode;
    }

    return 0 != info.Config.size();
}

bool SearchCompatibleFirmware(const sConfigInfo& configInfo, const sIdentifyInfo& devInfo, string& binaryFile, string &binaryCode)
{
    // This function search for compatible firmware and put firmware file name into firmwareList
    const vector<sFirmwareInfo> &fwInfoList = configInfo.Config;
    
    for (int i = 0, count = fwInfoList.size(); i < count; i++)
    {
        // Checking on this fwInfo
        const sFirmwareInfo& fwInfo = fwInfoList[i];
        
        // Checking for compatible model
        if (string::npos == devInfo.DeviceModel.find(fwInfo.DeviceModel)) continue;
        
        // Checking for compatible firmware
        const vector<string>& vsList = fwInfo.CompatibleList;
        if (vsList.end() == find(vsList.begin(), vsList.end(), devInfo.FirmwareVersion)) continue;
        
        // This fwInfo is compatible to devInfo
        binaryCode = fwInfo.FirmwareCode;
        binaryFile = fwInfo.FirmwareFile;
        return true;
    }
    
    return false;
}

bool VerifyChecksum(const string firmwareFile, const string &firmwareCode)
{
    MD5 md5;
    md5.update(firmwareFile);
    md5.finalize();

    string fwcode = firmwareCode;
    transform(fwcode.begin(), fwcode.end(), fwcode.begin(), ::tolower);

    string filecode = md5.toHexString();

    return 0 == filecode.compare(fwcode);
}

// -----------------------------------------------------------------------
// Utility functions
// -----------------------------------------------------------------------

void ReadTextFile(const string& fileName, string& text)
{
    ifstream fstr(fileName.c_str());
    text = string((istreambuf_iterator<char>(fstr)), istreambuf_iterator<char>());
}

bool ReadValue(const string& text, const string& key, string& value)
{
    // Search key and read its value
    size_t keypos = text.find(key);
    if (keypos == string::npos) return false;

    // Shift keypos to valuepos
    size_t valpos = keypos + key.length();

    // Search end-of-line position
    size_t endpos = text.find("\n", valpos);

    // Remove trailing spaces
    while((valpos < endpos) && isspace(text[valpos])) valpos++;
    while((valpos < endpos) && isspace(text[endpos])) endpos--;

    // Extract substring from valpos to endpos
    value = text.substr(valpos, endpos - valpos + 1);

    return value.length() != 0;
}

bool ReadConfigValue(const string& text, const string& key, string& value)
{
    string rawValue;
    if (false == ReadValue(text, key, rawValue)) return false;

    // Remove trailing spaces, '=', .. in rawValue
    const char* p = rawValue.c_str();
    while ((*p == ' ') || (*p == '=')) p++;

    value = string(p);

    return true;
}

void SplitString(const string& text, char delim, vector<string>& tokenList)
{
    tokenList.clear();

    string token;
    stringstream sstr(text);
    while (getline(sstr, token, delim))
    {
        tokenList.push_back(token);
    }
}

// -----------------------------------------------------------------------
// MD5 code
// -----------------------------------------------------------------------

MD5::MD5()
{
    init();
}

MD5::MD5(const std::string &text)
{
    init();
    update((U8*) text.c_str(), text.length());
    finalize();
}

void MD5::init()
{
    IsFinalized = false;

    BitCount[0] = 0;
    BitCount[1] = 0;

    // Magic initialization constants.
    State[0] = 0x67452301;
    State[1] = 0xefcdab89;
    State[2] = 0x98badcfe;
    State[3] = 0x10325476;
}

void MD5::transform(const U8 block[BLOCK_SIZE])
{
    U32 x[16];
    U32 a = State[0], b = State[1], c = State[2], d = State[3];
    
    Decode (x, block, BLOCK_SIZE);

    /* Round 1 */
    FF (a, b, c, d, x[ 0], MD5_S11, 0xd76aa478); /* 1 */
    FF (d, a, b, c, x[ 1], MD5_S12, 0xe8c7b756); /* 2 */
    FF (c, d, a, b, x[ 2], MD5_S13, 0x242070db); /* 3 */
    FF (b, c, d, a, x[ 3], MD5_S14, 0xc1bdceee); /* 4 */
    FF (a, b, c, d, x[ 4], MD5_S11, 0xf57c0faf); /* 5 */
    FF (d, a, b, c, x[ 5], MD5_S12, 0x4787c62a); /* 6 */
    FF (c, d, a, b, x[ 6], MD5_S13, 0xa8304613); /* 7 */
    FF (b, c, d, a, x[ 7], MD5_S14, 0xfd469501); /* 8 */
    FF (a, b, c, d, x[ 8], MD5_S11, 0x698098d8); /* 9 */
    FF (d, a, b, c, x[ 9], MD5_S12, 0x8b44f7af); /* 10 */
    FF (c, d, a, b, x[10], MD5_S13, 0xffff5bb1); /* 11 */
    FF (b, c, d, a, x[11], MD5_S14, 0x895cd7be); /* 12 */
    FF (a, b, c, d, x[12], MD5_S11, 0x6b901122); /* 13 */
    FF (d, a, b, c, x[13], MD5_S12, 0xfd987193); /* 14 */
    FF (c, d, a, b, x[14], MD5_S13, 0xa679438e); /* 15 */
    FF (b, c, d, a, x[15], MD5_S14, 0x49b40821); /* 16 */

    /* Round 2 */
    GG (a, b, c, d, x[ 1], MD5_S21, 0xf61e2562); /* 17 */
    GG (d, a, b, c, x[ 6], MD5_S22, 0xc040b340); /* 18 */
    GG (c, d, a, b, x[11], MD5_S23, 0x265e5a51); /* 19 */
    GG (b, c, d, a, x[ 0], MD5_S24, 0xe9b6c7aa); /* 20 */
    GG (a, b, c, d, x[ 5], MD5_S21, 0xd62f105d); /* 21 */
    GG (d, a, b, c, x[10], MD5_S22,  0x2441453); /* 22 */
    GG (c, d, a, b, x[15], MD5_S23, 0xd8a1e681); /* 23 */
    GG (b, c, d, a, x[ 4], MD5_S24, 0xe7d3fbc8); /* 24 */
    GG (a, b, c, d, x[ 9], MD5_S21, 0x21e1cde6); /* 25 */
    GG (d, a, b, c, x[14], MD5_S22, 0xc33707d6); /* 26 */
    GG (c, d, a, b, x[ 3], MD5_S23, 0xf4d50d87); /* 27 */
    GG (b, c, d, a, x[ 8], MD5_S24, 0x455a14ed); /* 28 */
    GG (a, b, c, d, x[13], MD5_S21, 0xa9e3e905); /* 29 */
    GG (d, a, b, c, x[ 2], MD5_S22, 0xfcefa3f8); /* 30 */
    GG (c, d, a, b, x[ 7], MD5_S23, 0x676f02d9); /* 31 */
    GG (b, c, d, a, x[12], MD5_S24, 0x8d2a4c8a); /* 32 */

    /* Round 3 */
    HH (a, b, c, d, x[ 5], MD5_S31, 0xfffa3942); /* 33 */
    HH (d, a, b, c, x[ 8], MD5_S32, 0x8771f681); /* 34 */
    HH (c, d, a, b, x[11], MD5_S33, 0x6d9d6122); /* 35 */
    HH (b, c, d, a, x[14], MD5_S34, 0xfde5380c); /* 36 */
    HH (a, b, c, d, x[ 1], MD5_S31, 0xa4beea44); /* 37 */
    HH (d, a, b, c, x[ 4], MD5_S32, 0x4bdecfa9); /* 38 */
    HH (c, d, a, b, x[ 7], MD5_S33, 0xf6bb4b60); /* 39 */
    HH (b, c, d, a, x[10], MD5_S34, 0xbebfbc70); /* 40 */
    HH (a, b, c, d, x[13], MD5_S31, 0x289b7ec6); /* 41 */
    HH (d, a, b, c, x[ 0], MD5_S32, 0xeaa127fa); /* 42 */
    HH (c, d, a, b, x[ 3], MD5_S33, 0xd4ef3085); /* 43 */
    HH (b, c, d, a, x[ 6], MD5_S34,  0x4881d05); /* 44 */
    HH (a, b, c, d, x[ 9], MD5_S31, 0xd9d4d039); /* 45 */
    HH (d, a, b, c, x[12], MD5_S32, 0xe6db99e5); /* 46 */
    HH (c, d, a, b, x[15], MD5_S33, 0x1fa27cf8); /* 47 */
    HH (b, c, d, a, x[ 2], MD5_S34, 0xc4ac5665); /* 48 */

    /* Round 4 */
    II (a, b, c, d, x[ 0], MD5_S41, 0xf4292244); /* 49 */
    II (d, a, b, c, x[ 7], MD5_S42, 0x432aff97); /* 50 */
    II (c, d, a, b, x[14], MD5_S43, 0xab9423a7); /* 51 */
    II (b, c, d, a, x[ 5], MD5_S44, 0xfc93a039); /* 52 */
    II (a, b, c, d, x[12], MD5_S41, 0x655b59c3); /* 53 */
    II (d, a, b, c, x[ 3], MD5_S42, 0x8f0ccc92); /* 54 */
    II (c, d, a, b, x[10], MD5_S43, 0xffeff47d); /* 55 */
    II (b, c, d, a, x[ 1], MD5_S44, 0x85845dd1); /* 56 */
    II (a, b, c, d, x[ 8], MD5_S41, 0x6fa87e4f); /* 57 */
    II (d, a, b, c, x[15], MD5_S42, 0xfe2ce6e0); /* 58 */
    II (c, d, a, b, x[ 6], MD5_S43, 0xa3014314); /* 59 */
    II (b, c, d, a, x[13], MD5_S44, 0x4e0811a1); /* 60 */
    II (a, b, c, d, x[ 4], MD5_S41, 0xf7537e82); /* 61 */
    II (d, a, b, c, x[11], MD5_S42, 0xbd3af235); /* 62 */
    II (c, d, a, b, x[ 2], MD5_S43, 0x2ad7d2bb); /* 63 */
    II (b, c, d, a, x[ 9], MD5_S44, 0xeb86d391); /* 64 */

    State[0] += a;
    State[1] += b;
    State[2] += c;
    State[3] += d;

    // Zeroize sensitive information.
    memset(x, 0, sizeof x);
}

void MD5::update(const string &filename)
{
    ifstream fstr;

    fstr.open(filename.c_str(), ios::in | ios::binary);
    if (false == fstr.is_open()) return;

    fstr.seekg(0, fstr.end); U32 size = fstr.tellg(); fstr.seekg(0, fstr.beg);
    U8* buffer = new U8[size]; fstr.read((char*) buffer, size); fstr.close();

    update(buffer, size);
    delete buffer;
}

void MD5::update(const U8 input[], U32 length)
{
    U32 index = BitCount[0] / 8 % BLOCK_SIZE;

    if ((BitCount[0] += (length << 3)) < (length << 3)) BitCount[1]++;
    
    BitCount[1] += (length >> 29);

    U32 firstpart = 64 - index;

    U32 i;
    
    if (length >= firstpart)
    {
        memcpy(&Buffer[index], input, firstpart);
        
        transform(Buffer);

        // Transform chunks of BLOCK_SIZE (64 bytes)
        for (i = firstpart; i + BLOCK_SIZE <= length; i += BLOCK_SIZE) transform(&input[i]);
        
        index = 0;
    }
    else i = 0;

    memcpy(&Buffer[index], &input[i], length-i);
}

void MD5::finalize()
{
    static unsigned char padding[64] = {
        0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    if (!IsFinalized) {
        // Save number of bits
        unsigned char bits[8];
        Encode(bits, BitCount, 8);

        // pad out to 56 mod 64.
        U32 index = BitCount[0] / 8 % 64;
        U32 padLen = (index < 56) ? (56 - index) : (120 - index);
        update(padding, padLen);

        // Append length (before padding)
        update(bits, 8);

        // Store state in digest
        Encode(Digest, State, 16);

        // Zeroize sensitive information.
        memset(Buffer, 0, sizeof Buffer);
        memset(BitCount, 0, sizeof BitCount);

        IsFinalized = true;
    }
}

bool MD5::getDigestBuffer(U8 *buffer) const
{
    if (!IsFinalized || (NULL == buffer)) return false;

    memcpy(buffer, Digest, sizeof(Digest));

    return true;
}
// return hex representation of digest as string
string MD5::toHexString() const
{
    if (!IsFinalized) return "";

    char buf[33];
    for (int i = 0; i < 16; i++)
        sprintf(buf + i*2, "%02x", Digest[i]);
	
    buf[32] = 0;

    return std::string(buf);
}

// ------------------------------------------------------------------------------------
// Static utilities
// ------------------------------------------------------------------------------------

U32 MD5::F(U32 x, U32 y, U32 z) 
{
    return x&y | ~x&z;
}

U32 MD5::G(U32 x, U32 y, U32 z) 
{
    return x&z | y&~z;
}

U32 MD5::H(U32 x, U32 y, U32 z) 
{
    return x^y^z;
}

U32 MD5::I(U32 x, U32 y, U32 z) 
{
    return y ^ (x | ~z);
}

U32 MD5::rotate_left(U32 x, int n) 
{
    return (x << n) | (x >> (32-n));
}

void MD5::FF(U32 &a, U32 b, U32 c, U32 d, U32 x, U32 s, U32 ac) 
{
    a = rotate_left(a+ F(b,c,d) + x + ac, s) + b;
}

void MD5::GG(U32 &a, U32 b, U32 c, U32 d, U32 x, U32 s, U32 ac) 
{
    a = rotate_left(a + G(b,c,d) + x + ac, s) + b;
}

void MD5::HH(U32 &a, U32 b, U32 c, U32 d, U32 x, U32 s, U32 ac) 
{
    a = rotate_left(a + H(b,c,d) + x + ac, s) + b;
}

void MD5::II(U32 &a, U32 b, U32 c, U32 d, U32 x, U32 s, U32 ac) 
{
    a = rotate_left(a + I(b,c,d) + x + ac, s) + b;
}

void MD5::Decode(U32 output[], const U8 input[], U32 len)
{
    for (unsigned int i = 0, j = 0; j < len; i++, j += 4)
    {
        output[i] = 
            ((U32)input[j]) | 
            (((U32)input[j + 1]) << 8) |
            (((U32)input[j + 2]) << 16) | 
            (((U32)input[j + 3]) << 24);   
    }
}

void MD5::Encode(U8 output[], const U32 input[], U32 len)
{
    for (U32 i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = input[i] & 0xff;
        output[j + 1] = (input[i] >> 8) & 0xff;
        output[j + 2] = (input[i] >> 16) & 0xff;
        output[j + 3] = (input[i] >> 24) & 0xff;
    }
}

// -----------------------------------------------------------------------
// End
// -----------------------------------------------------------------------

