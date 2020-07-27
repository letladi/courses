/**
 * strcpy(str, "tire-bouchon"); str = "tire-bouchon"
 * strcpy(&str[4], "d-or-wi"); str = "<.>do-or-wi" (where "<.>" is the initial first 4 characters in index 0-3 )
 * strcat(str, "red?"); str = "<.>red?" (where "<.>" is the initial characters in str before the concatenation)
 * ❌
 * "tired-or-wired?"
 */ 