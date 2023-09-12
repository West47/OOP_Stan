
#include"intarray.hpp"
#include <stdio.h>

void list_output(IntArray& parray){
  IntArray temp;
  temp = parray;
  printf("\n");
  if (temp.Size() == 0) {
    printf("+-+\n| |\n+-+");
  }
  else {
    temp.GoToLeft();
    temp.Fetch();
    if (temp.Size() > 1) {
      for (int i=0; i<=temp.Size()-1; i++){
	printf("+----");
      }
    }
    else printf("+----");
    printf("+");
    printf("\n");
    printf("|%4i",temp.GetElement());
    if (temp.Size() > 1){
      while (temp.GoToNext()){
	temp.Fetch();
	printf("|%4i",temp.GetElement());
      }
    }
    printf("|\n");
    if (temp.Size() > 1) {
      for (int i=0; i<=temp.Size()-1; i++)
	{printf("+----");
	}
    }
    else printf("+----");
        printf("+\n");
    if(temp.First()<temp.Last()){
      for (int i=temp.First(); i<=temp.Last(); i++){
	printf("%5i",i);
      }
    } else printf("%5i",temp.First());
  }
  printf("\n");
}

//вывод списка при добавлении элемента справа
void list_(IntArray& array, int element,const char* name){
  printf("\n%s + %i",name,element);
  if (array + element) {
    printf("\nOK");
  }
  else printf("\nNoMemory");
}

void _list(IntArray& array, int element,const char* name){
    printf("\n%i + %s",element,name);
	if (element + array) {
		    printf("\nOK");
		} else printf("\nNoMemory");
};

//вывод списка при добавлении элемента слева
void list_delete(IntArray& array, const char* name){
  printf("\n%s-- ==", name);
  if (array--) {
    printf(" %i\nOK", array.GetElement());
  }
  else printf(" Array Is Empty\n\n");
}

//вывод списка при удалении элемента справа
void delete_list(IntArray& array, const char* name){
  printf("\n--%s ==",name);
  if (--array) {
    printf(" %i\n", array.GetElement());
  }
  else printf(" Array Is Empty\n\n");
}

int main(){
    IntArray array01;

    list_output(array01);
    printf("IntArray array01");
    for(int i=1;i<=6;i+=2){
      list_(array01, i, "array01");
      list_output(array01);
      _list(array01, i+1, "array01");
      list_output(array01);
    }
    
    array01[1] = 77;
    array01.Fetch();
    printf("\narray01[1] == %i\n",array01.GetElement());
    list_output(array01);

    
    for(int i=1;i<=8;i+=2){
      list_delete(array01,"array01");
      list_output(array01);
      delete_list(array01,"array01");
      list_output(array01);
    }
   
    IntArray array02(10);
    printf("\nIntArray array02(10) == OK");
    list_output(array02);
    for(int i=10;i<=80;i+=20){
      list_(array02, i, "array02");
      list_output(array02);
      _list(array02, i+10, "array02");
      list_output(array02);
    }
    
    array01 = array02;
    printf("\narray01 = array02 == OK\narray01:");
    list_output(array01);
    printf("array02:");
    list_output(array02);

    IntArray array03(array02);
    printf("\n\nIntArray array03(array02) == OK\narray03:");
    list_output(array03);
    array03[9] = 99;
    array03.Fetch();
    printf("\narray03[9] == %i",array03.GetElement());
    list_output(array03);
    

    IntArray array04(10);
    list_output(array04);
    return 0;
}
