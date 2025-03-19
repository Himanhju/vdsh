
int sh_init(void);

void sh_clean(void);

/**
*  @brief       Gets The PATH Variable.
*  @returns     Returns The Value Of PATH.
*  @warning     Will Not Return Correctly If sh_init() Is Not Ran Before It.
*/
char* get_PATH(void);

/**
*  @brief       Gets The PWD Variable.
*  @returns     Returns The Value Of PWD.
*  @warning     Will Not Return Correctly If sh_init() Is Not Ran Before It.
*/
char* get_PWD(void);



// /** is the begining of it
/* 
*	@brief	a breif explination of what it does
*	@param	parameter 1
*	@param	parameter 2
*	@param	parameter 3
*	@param	parameter 4
*	@params  if stdarg is included the n this is ...
*	@example and example
*	@returns info about what it returns
*	@warning warning for the function
*/