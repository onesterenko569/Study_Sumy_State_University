#include <stdio.h>
#include <conio.h>
int main()
{
	char st[] = "M#e####ni# p#odob##ayet#s##ya# in##fo##mat#yka#";
	char sym = '#'; /*символ, що вилучається*/
	char* pk, * pn;

	for (pk = pn = st; *pk != '\0'; pk++)
		if (*pk != sym)
			*pn++ = *pk;
	*pn = '\0'; /*фіксація кінця нового рядка*/
	printf("Ryadok pislya vyluchenya : % s \n", st);

	return 0;
}
