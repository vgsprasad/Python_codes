#include<stdio.h>

int main()
{
        int        value;
        int       index;
        int       line_index;
        int       addr;
        int         ret_val = 0;
        char            temp_buf[256];
	char buf[1024];

	addr =0;

        /* Split display into address & maybe 16 values a line */
        for (line_index = 0; line_index < 256;
             line_index += 16)
        {
                ret_val += sprintf(temp_buf, "\nOffset 0x%x: ", line_index);
                strcat(buf,temp_buf);
                for (index = 0; index < 16; index++)
                {
			value = addr+line_index*16+index;
                        ret_val += sprintf(temp_buf, "%x  ", value);
                        strcat(buf, temp_buf);
                }
        }
        strcat(buf, "\n");
	printf("%s", buf);
        return ret_val;
}

