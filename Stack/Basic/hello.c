for(int i = 0; i <= str.length; i++){
     if(str[i] != ' ' || str[i] != "\n"){
      push(str[i]);
    }
    else{
      while(!isEmpty()){
        printf("%c",pop());
      }
      printf(" ");
    }
}
