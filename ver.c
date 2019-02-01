int compareVersion(char* version1, char* version2) {

	char MJ1[100], MJ2[100], MN1[100], MN2[100];
	int mj1, mj2, mn1, mn2;
	if (strstr(version1, ".") || strstr(version2, ".")) {
		sscanf(version1, "%s.%s", MJ1, MN1);
		sscanf(version2, "%s.%s", MJ2, MN2);
		mj1 = strtol(MJ1, NULL, 10);
		mj2 = strtol(MJ2, NULL, 10);
		mn1 = strtol(MN1, NULL, 10);
		mn2 = strtol(MN2, NULL, 10);
		if (mj1 > mj2) {
			return 1;
		} 
		else if (mj1 == mj2) { 
			if (mn1> mn2) {
				return 1;
			}
			else if (mn1 == mn2) {
				return 0;
			}
			else {
				return -1;
			}
		} else 
		{
			return -1;
		}
	}
	else {
		sscanf(version1, "%s", MJ1);
		sscanf(version2, "%s", MJ2);
		mj1 = strtol(MJ1, NULL, 10);
		mj2 = strtol(MJ2, NULL, 10);
		if (mj1 > mj2 ) {
			return 1;
		}
		else if (mj1 == mj2) {
			return 0;
		}
		else {
			return -1;
		}
	}
}
