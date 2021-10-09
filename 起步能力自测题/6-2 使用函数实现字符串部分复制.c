void strmcpy( char *t, int m, char *s ) {
	int i=m-1, j=0;
	while ( t[i] != '\0' ){//如果字符串t没有结束就继续复制
		s[j] = t[i];
        j++;
        i++;//两下标右移
    }
	s[j]='\0';//字符串尾结束符
}