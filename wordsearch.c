typedef struct {
	WordDictionary *word[26];
	char val;
} WordDictionary;

/** Initialize your data structure here. */
WordDictionary* wordDictionaryCreate() {
	WordDictionary *temp;
	temp = malloc(sizeof(WordDictionary));
	if (!temp ) {
		printf("Malloc failure\n");
		return NULL);
	}

	for (int i =0; i<26;i++)
		temp->word[i] = NULL;
	return temp;
    
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char* word) {
	int len = strlen(word);
	int i ;
	int idx;
	WordDictionary *temp = obj
	WordDictionary *newnode;
	for(i =0; i<len;i++)
	{
		idx = word[i]-'97';
		if (temp->word[idx]) {
			temp = temp->word[idx];
		}
		else
		{
			newnode = wordDictionaryCreate();
			newnode->val = word[i];
			temp->word[idx] = newnode;
			temp = newnode;
		}
	}
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char* word) {
	bool ret
	for (int i = 0; i<26; i++) 
		ret = ret || myversion(obj->word[i],word, 0);
	return ret
}
bool myversion(WordDictionary *obj, char *word, int start) {
	int len = strlen(word);
	WordDictionary * temp = obj;
	bool ret = false;
	if (start >=len) {
		return false;
	switch (word[start]) {
		case '.': int j;
			  for(j = 0; j<26;j++) {
				ret = ret || wordDictionarySearch(obj->word[j], word, start+1);
			  }
			  break;
		default:  int idx = word[start]-97;
			  if (obj->word[idx]) 
				return ((obj->val == word[start]) && 
				       wordDictionarySearch(obj->word[idx], word, start+1));
			  else
				ret = false;
	}
	return ret;
}

void wordDictionaryFree(WordDictionary* obj) {
	free(obj);
    
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * struct WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 * bool param_2 = wordDictionarySearch(obj, word);
 * wordDictionaryFree(obj);
 */
