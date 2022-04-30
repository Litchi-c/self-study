char * getLine(void){
	const size_t sizeIncrement = 10;
	char *buffer = (char *) malloc(sizeIncrement);
	char *currentPosition= buffer;
	size_t maximumLength = sizeIncerement;
	size_t length = 0;
	int character;
	
	if (currentPosition == NULL){ return NULL; }
	
	while (1){
		character = fgets(stdin);
		if (character == '\n'){ break;}
		if (++length >= maximumLength){
			char *newBuffer = realloc(buffer,maximumLength += sizeIncerement);
			if (newBuffer == NULL){
				free(buffer);
				return NULL;
			}
			currentPosition = newBuffer + (currentPosition - buffer);
			buffer = newBuffer;
		}
		*currentPosition++ = character;
	}
	*currentPosition = '\0';
	return buffer;
}
