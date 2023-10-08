#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct record {
char name[64]; //utf16
char surname[32]; //utf8
char gender;
char email[32];
char phone_number[16];
char address[32];
char level_of_education[8];
unsigned int income_level; // given little-endian
unsigned int expenditure; // given big-endian
char currency_unit[16];
char currentMood[32];
float height;
unsigned int weight;
};

void createdata(FILE *fb,struct record fetchedRecord, int row_count)
{
 fprintf ( fb,"\t<row id=\"%d\">\n", row_count);
 fprintf ( fb,"\t\t<name>%s</name>\n",fetchedRecord.name);
 fprintf ( fb,"\t\t<surname>%s</surname>\n",fetchedRecord.surname);
 fprintf ( fb,"\t\t<gender>%c</gender>\n",fetchedRecord.gender);
 fprintf ( fb,"\t\t<email>%s</email>\n",fetchedRecord.email);
 fprintf ( fb,"\t\t<phone_number>%s</phone_number>\n",fetchedRecord.phone_number);
 fprintf ( fb,"\t\t<address>%s</address>\n",fetchedRecord.address);
 fprintf ( fb,"\t\t<level_of_education>%s</level_of_education>\n",fetchedRecord.level_of_education);
 fprintf ( fb,"\t\t<income_level>%d</income_level>\n",fetchedRecord.income_level);
 fprintf ( fb,"\t\t<expenditure>%d</expenditure>\n",fetchedRecord.expenditure);
 fprintf ( fb,"\t\t<currency_unit>%s</currency_unit>\n",fetchedRecord.currency_unit);
 fprintf ( fb,"\t\t<currentMood>%s</currentMood>\n",fetchedRecord.currentMood);
 fprintf ( fb,"\t\t<height>%f</height>\n",fetchedRecord.height);
 fprintf ( fb,"\t\t<weight>%d</weight>\n",fetchedRecord.weight);
//  fprintf ( fb,"\t</row>\n");fprintf(fxml,"\t<row id = %d>\n",i+1);
   // fprintf(fb,"\t\t<%s>%s</%s>\n",headers.name,fetchedRecord.name,headers.name);
   // fprintf(fb,"\t\t<%s>%s</%s>\n",headers.surname,fetchedRecord.surname,headers.surname);
   // fprintf(fb,"\t\t<%s>%c</%s>\n",headers.gender,fetchedRecord.gender,headers.gender);
   // fprintf(fb,"\t\t<%s>%s</%s>\n",headers.email,fetchedRecord.email,headers.email);
   // fprintf(fb,"\t\t<%s>%s</%s>\n",headers.phone_number,fetchedRecord.phone_number,headers.phone_number);
   // fprintf(fb,"\t\t<%s>%s</%s>\n",headers.address,fetchedRecord.address,headers.address);
   // fprintf(fb,"\t\t<%s>%s</%s>\n",headers.level_of_education,fetchedRecord.level_of_education,headers.level_of_education);
   // fprintf(fb,"\t\t<%s>%u</%s>\n",headers.income_level,fetchedRecord.income_level,headers.income_level);
   // fprintf(fb,"\t\t<%s>%u</%s>\n",headers.expenditure,fetchedRecord.expenditure,headers.expenditure);
   // fprintf(fb,"\t\t<%s>%s</%s>\n",headers.currency_unit,fetchedRecord.currency_unit,headers.currency_unit);
   // fprintf(fb,"\t\t<%s>%s</%s>\n",headers.currentMood,fetchedRecord.currentMood,headers.currentMood);
   // fprintf(fb,"\t\t<%s>%f</%s>\n",headers.height,fetchedRecord.height,headers.height);
   // fprintf(fb,"\t\t<%s>%u</%s>\n",headers.weight,fetchedRecord.weight,headers.weight);
   fprintf(fb,"\t</row>\n");

}

int main(int argc,char *argv[])
{
   int n;
   // int count = 0;
   // char c;
   FILE *fptr;
   FILE *fb;
   fptr =fopen(argv[1],"r");
   fb =fopen(argv[2],"w");
   struct record records[50],garbage[1];
   if ((fptr = fopen(argv[1],"rb")) == NULL){
       printf("Error! opening file");
       exit(1);
   }
   // for (c = getc(fptr); c != EOF; c = getc(fptr))
   //      if (c == '\n') // Increment count if this character is newline
   //          count = count + 1;
   // printf("%d",count);
   fread(&garbage,sizeof(garbage),1,fptr);
   fprintf ( fb,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<records>\n");
   for(n = 0; n < 50; n++)
   {
      fread(&records[n],sizeof(struct record),1,fptr);
      // fread(&records[n].name, sizeof(records[n].name), 1, fptr);
      // fread(&records[n].surname, sizeof(records[n].surname), 1, fptr);
      // fread(&records[n].gender, sizeof(records[n].gender), 1, fptr);
      // fread(&records[n].email, sizeof(records[n].email), 1, fptr);
      // fread(&records[n].phone_number, sizeof(records[n].phone_number), 1, fptr);
      // fread(&records[n].address, sizeof(records[n].address), 1, fptr);
      // fread(&records[n].level_of_education, sizeof(records[n].level_of_education), 1, fptr);

      // fread(&records[n].income_level, sizeof(records[n].income_level), 1, fptr);
      
      // fread(&records[n].expenditure, 1,sizeof(records[n].expenditure), fptr);
      // unsigned int no_of_bits = sizeof(&records[n].expenditure)*8;
      // unsigned int reverse_num = 0;
      // int i;
      // for(i = 0; i < no_of_bits;i++){
      //    if((records[n].expenditure & (1<<i))){
      //       reverse_num |= 1 << ((no_of_bits-1)-i);
      //    }
      // }
      // records[n].expenditure = reverse_num;
      // fread(&records[n].currency_unit, sizeof(records[n].currency_unit), 1, fptr);
      // fread(&records[n].currentMood, sizeof(records[n].currentMood), 1, fptr);
      // fread(&records[n].height, sizeof(records[n].height), 1, fptr);
      // fread(&records[n].weight, sizeof(records[n].weight), 1, fptr);
      createdata(fb,records[n],n);
   }
   fprintf ( fb,"</records>\n");
   fclose(fb);
   fclose(fptr); 
   system("xmllint --schema hw1_xsd.xsd hw_1_xml.xml");
   return 0;
}