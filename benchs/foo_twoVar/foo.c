/*
void foo0(double x, double y){
  if (x+y<=5)
    return;
}
*/

//it is user's responsibility to make X[0], X[1] within the bound
void foo(double* X){
      if (X[0]+X[1]<=5)
  //  if (X[0]==5 || X[1]==9)
  //DB
  //if (X[1]==9 & X[0]==5)
    return;
}

/*
tf_type tf_convert(double x,double y){
  int max_length=2;
  double inputs[]={x,y};
  return std::pair(inputs,max_len);
}
*/
