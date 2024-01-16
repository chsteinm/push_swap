#include "push_swap.h"

int main(){
	char *str;
	for (int i = 2; i < 501; i++){
		str = ft_itoa_base(i, "01");
		printf("- %s -", str);
		free(str);
		str = ft_itoa_base(i, "012");
		printf("- %s -", str);
		free(str);
		str = ft_itoa_base(i, "0123");
		printf("- %s -", str);
		free(str);
		str = ft_itoa_base(i, "01234");
		printf("- %s -", str);
		free(str);
		str = ft_itoa_base(i, "012345");
		printf("- %s -", str);
		free(str);
		str = ft_itoa_base(i, "0123456");
		printf("- %s -", str);
		free(str);
		str = ft_itoa_base(i, "01234567");
		printf("- %s -", str);
		free(str);
		str = ft_itoa_base(i, "012345678");
		printf("- %s -", str);
		free(str);
		str = ft_itoa_base(i, "0123456789");
		printf("- %s -", str);
		free(str);
		printf("\n");}
	return 0;
}