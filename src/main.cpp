#include <Arduino.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <Wire.h>
#pragma once
#define pi 3.1415926535
#define switch_pin  5
#define IN1mo1 1
#define IN2mo1 2
#define IN1mo2 1
#define IN2mo2 1
#define IN1mo3 1
#define IN2mo3 1
#define IN1mo4 1
#define IN2mo4 1
int ball1,ball2,ball3,ball4,ball5,ball6,ball7,ball8,ball9,ball10,ball11,ball12,ball13,ball14,ball15,ball16,line1,line2,line3,line4,line5,line6,line7,line8,line9,line10,line11,line12,line13,line14,line15,line16;
float x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,r,deg,tate,yoko,balltate,ballyoko,lin;
unsigned long time_new, time_old = 0;
int ba[16]={ball1,ball2,ball3,ball4,ball5,ball6,ball7,ball8,ball9,ball10,ball11,ball12,ball13,ball14,ball15,ball16};
float x[]={x1,x2,x3,x4,x5};
float y[]={y1,y2,y3,y4,y5};
void ba_val();
float ball_tate();  //縦
float ball_yoko();
float ball_deg(); 
void pin();
void swap(int *pa, int *pb);
void bubble_sort(int n, int a[]);
void sort();
float degfunc(float tardeg);
void motor(float angle);
float line();
float degfunc2(float b);
void  AC();
void setup(){
for (int i =0; i<16; i++){
  ba[i]=0;
}
pin();
}
void loop() {

}
// put function definitions here:
void pin(){
  pinMode(9,INPUT);
  pinMode(7,INPUT);
  pinMode(5,INPUT);
  pinMode(3,INPUT);
  pinMode(35,INPUT);
  pinMode(31,INPUT);
  pinMode(29,INPUT);
  pinMode(25,INPUT);
  pinMode(23,INPUT);
  pinMode(21,INPUT);
  pinMode(19,INPUT);
  pinMode(17,INPUT);
  pinMode(15,INPUT);
  pinMode(27,INPUT);
  pinMode(13,INPUT);
  pinMode(11,INPUT);
}
void ba_val(){
  time_new= micros();
  int val1= PINA & _BV(6);
  int val2= PINC & _BV(7);
  int val3= PINL & _BV(7);
  int val4= PINE & _BV(5);
  int val5= PINC & _BV(2);
  int val6= PINC & _BV(6);
  int val7= PINA & _BV(7);
  int val8= PINA & _BV(3);
  int val9= PINA & _BV(1);
  int val10= PIND & _BV(0);
  int val11= PIND & _BV(2);
  int val12= PINH & _BV(0);
  int val13= PINJ & _BV(0);
  int val14= PINL & _BV(7);
  int val15= PINC & _BV(7);
  int val16= PINA & _BV(6);
  int val[]={val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11,val12,val13,val14,val15,val16};
if (time_new % 833 !=0){
 for (int i=0; i<=15; i++){
  if (time_new==0){
     ba[i]=0;
}else{
  if (val[i]==0){
    ba[i]=ba[i]+1;
  }else{
    ba[i]=ba[i];
  }
    }
}
}else{//リセット
for (int i = 0; i < 16; i++) {
     ba[i] = 0;
}
}
}
void swap(int *pa, int *pb)
{
  int tmp;
 
  tmp = *pa;
  *pa = *pb;
  *pb = tmp;
}
void bubble_sort(int n, int a[])
{
  int i, j;
 
  for (i = 0; i < n; i++) {
    for (j = 1; j < n - i; j++) {
      if (a[j] < a[j - 1]) {
        swap(&a[j], &a[j - 1]);
      }
    }
  }
}
void sort(){
  bubble_sort(16,ba);
  for (int n =15; n>10; n--){
    if (ba[n]==ball1){//90
      x[15-n]=ball1;
      y[15-n]=0;
    } else if (ba[n]==ball2){//67.5
      x[15-n]=0.3826834*ball2;
      y[15-n]=0.9238795*ball2;
    }else if (ba[n]==ball3){//45
      x[15-n]=0.7071067*ball3;
      y[15-n]=0.7071067*ball3;
    }else if (ba[n]==ball4){//22.5
      x[15-n]=0.92387953*ball4;
      y[15-n]=0.38268343*ball4;
    }else if (ba[n]==ball5){//0
      x[15-n]=ball5;
      y[15-n]=0;
    }else if (ba[n]==ball6){//337.5
      x[15-n]=0.9238795*ball6;
      y[15-n]=-0.3826834*ball6;
    }else if (ba[n]==ball7){//315
      x[15-n]=0.7071067*ball7;
      y[15-n]=-0.7071067*ball7;
    }else if (ba[n]==ball8){//292.5
      x[15-n]=0.38268343*ball8;
      y[15-n]=-0.9238795*ball8;
    }else if (ba[n]==ball9){//270
      x[15-n]=0;
      y[15-n]=-1*ball9;
    }else if (ba[n]==ball10){//247.5
      x[15-n]=-0.3826834*ball10;
      y[15-n]=-0.9238795*ball10;
    }else if  (ba[n]==ball11){//225
      x[15-n]=-0.7071067*ball11;
      y[15-n]=-0.7071067*ball11;
    }else if (ba[n]==ball12){//202.5
      x[15-n]=-0.9238795*ball12;
      y[15-n]=-0.3826834*ball12;
    }else if (ba[n]==ball13){//180
      x[15-n]=-1*ball13;
      y[15-n]=0;
    }else if (ba[n]==ball14){//157.5
      x[15-n]=-0.9238795*ball14;
      y[15-n]=0.3826834*ball14;
    }else if (ba[n]==ball15){//135
      x[15-n]=-0.7071067*ball15;
      y[15-n]=0.7071067*ball15;
    }else if (ba[n]==ball16){//112.5
      x[15-n]=-0.3826834*ball16;
      y[15-n]=0.9238795*ball16;
    }
  }
 
}
float ball_deg(){
  
    ba_val();
    sort();
    float ret = atan2f(x1+x2+x3+x4+x5,y1+y2+y3+y4+y5);
    float deg_old= (180/pi)* ret;
  return degfunc2(deg_old);
}
float degfunc(float tardeg){
  if (tardeg <180) {
    return 2*tardeg;
  } else  (tardeg >=180);{
    if (tardeg +90 >360){
      return (tardeg+90)-360;
    }else {
      return tardeg+90;
    }
  }
}
void motor(float angle){
 int motor_speed_1=100*sin((angle-45)*(180/pi));
 int motor_speed_2=100*sin((angle-135)*(180/pi));
 int motor_speed_3=100*sin((angle-225)*(180/pi));
 int motor_speed_4=100*sin((angle-315)*(180/pi));

 if (motor_speed_1>=0){//後で変更
   analogWrite(IN1mo1,0);
   analogWrite(IN2mo1,motor_speed_1);
 }else {
   analogWrite(IN1mo1,-motor_speed_1);
   analogWrite(IN2mo1,0);
 }
 if (motor_speed_2>=0){//後で変更
  analogWrite(IN1mo2,0);
  analogWrite(IN2mo2,motor_speed_2);
 }else {
  analogWrite(IN1mo2,-motor_speed_2);
  analogWrite(IN2mo3,0);
 }
 if (motor_speed_3>=0){//後で変更
  analogWrite(IN1mo3,0);
  analogWrite(IN2mo3,motor_speed_3);
 }else {
  analogWrite(IN1mo3,-motor_speed_3);
  analogWrite(IN2mo3,0);
 }
 if (motor_speed_4>=0){//後で変更
  analogWrite(IN1mo4,0);
  analogWrite(IN2mo4,motor_speed_4);
 }else {
  analogWrite(IN1mo4,-motor_speed_4);
  analogWrite(IN2mo4,0);
 }
}
float line (){
   line1 = 1;
   line2 = 1;
   line3 = 1;
   line4 = 1;
   line5 = 1;
   line6 = 1;
   line7 = 1;
   line8 = 1;
   line9 = 1;
   line10 = 1;
   line11 = 1;
   line12 = 1;
   line13 = 1;
   line14 = 1;
   line15 = 1;
   line16 = 1;
  int lin[] = {line1,line2,line3,line4,line5,line6,line7,line8,line9,line10,line11,line12,line13,line14,line15,line16};
  if (line1+line2+line3+line4+line5+line6+line7+line8+line9+line10+line11+line12+line13+line14+line15+line16==1){
    for (int i=0;i<16; i++ ){
      if (lin[i]==1){
        if (i<5){
        return 270-(22.5*i);
        } else {
          if (270-22.5*i>360){
            return (270-22.5*i)-360;
          } else {
            return 270-22.5*i;
          }
        }
    }
    else{//何もしない
     return -5;
    }
    }
}
else{
  return 0;
}
}
float degfunc2(float b){
 if ((0<b) && (b<=90)){
  b=90-b;
 } else if ((90<b) && (b<=180)){
  b=360-b;
 } else if ((180<b) && (b<=270)){
  b=450-b;
 } else if ((270<b)&& (b<=360)){
  b=450-b;
 }
 else if (b==0){
  b=360;
 }
 return b;
}
void AC(){

}
//保存用
/*
int situ,situ_line,line_flag=0;
while (1){
if (digitalread(switch_pin)==0){
if (situ==0){//最初
AC();
situ=10;
} else if (situ==10){  //ボール探す
deg=ball_deg();
deg=degfunc(deg);
deg=degfunc2(deg);
situ==20;
}else if (situ==20){//ラインのチェック
lin=line();
if (lin>0){
  if ((line_flag-5<=lin) && (lin<=line_flag+5)){
    deg=360;
    situ==30;
  }else {
    deg=lin;
    situ==30;
  }
}
}
else if (situ==30){//motor
  motor(degfunc2(deg));
  situ==0;
}
}else{
  analogWrite(IN1mo1,0);
  analogWrite(IN2mo1,0);
  analogWrite(IN1mo2,0);
  analogWrite(IN2mo2,0);
  analogWrite(IN1mo3,0);
  analogWrite(IN2mo3,0);
  analogWrite(IN1mo4,0);
  analogWrite(IN2mo4,0);
}
}
*/

