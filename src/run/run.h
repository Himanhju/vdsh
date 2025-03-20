//gets the executible file from PATH


/**
*	@brief	 Gets The Best Path To An Executible Given a Command.
*	@param	 command Command To Find Executible Of.
*	@example get_exe("ls"); returns "/usr/bin/ls" or "/bin/ls" if /usr/bin is not found.
*	@returns Returns the Best Path With an Executible File.
*	@warning Will Not have a Path If sh_init() Is Not Run First.
*/
char* get_exe(char* command);