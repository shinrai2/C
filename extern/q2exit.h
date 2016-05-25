int isExit (void);
int isExit (void) //1 to exit , 0 to continue
{
	char t1,t2;
	t1 = getchar();
	t2 = getchar();
	if (t1 == 'q' && t2 == '\n')
	{
		return 1;
	}
	ungetc (t2,stdin);
	ungetc (t1,stdin);
	return 0;
}