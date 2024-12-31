#include"prof.h"

int give_index(char c){
    if(c == 95)return 52;
    if(c < 97 && c > 64){
        return  c - 65 + 26;
    }
    else if(c > 96){
        return c - 97 ;
    }
    else{
        return c - 48 + 53;
    }
}

trie_node* create_trie_node(){
    trie_node* root =(trie_node*) malloc(sizeof(trie_node));
    root->list = (trie_node**) calloc(sizeof(trie_node*),63);
    root->is_end = false;
    return root;
}

void insert_in_trie(trie_node* root , char* string){
    int n = strlen(string);
    for(int i=0;i<n;i++){
        int k = give_index(string[i]);
        if(!root->list[k]){
            root->list[k] = create_trie_node();
        }
        root = root->list[k];
    }
    root->is_end = true;
    return ;
}

bool is_in_trie(trie_node* root , char* string){
    bool out = true; 
    int n = strlen(string);
    for(int i=0;i<n;i++){
        int k = give_index(string[i]);
        if(!root->list[k])return false;
        root = root->list[k];
    }
    return root->is_end;
}


