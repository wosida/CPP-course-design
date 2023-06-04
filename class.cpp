//
// Created by 李冬阳 on 2023/5/25.
//
#include"class.h"


Epidemic::Epidemic() {

    country=" ";
    city=" ";
    for(int i=0;i<30;i++){
        Newcases[i]=0;
        Existcases[i]=0;
        Acumulatedcases[i]=0;
        Curedcases[i]=0;
        Deathcases[i]=0;
    }
    Forecastcases=0;
}
int Preprocess(double* input, int size) {
    double max_value = *max_element(input, input + size);
    for (int i = 0; i < size; i++) {
        input[i] /= max_value;
    }
   return max_value;
}
double Postprocess(double output, double* input, int size,int max_value) {
    for (int i = 0; i < size; i++) {
        input[i] *= max_value;
    }
    return output * max_value;
}
void Epidemic::Forecast() {
    double input[15];
    copy(Newcases + 1, Newcases + 16, input);
     Preprocess(input, 15);
    // 构建神经网络
    const int inputnodes = 15;
    const int hidenodes = 8;
    const int outputnodes = 1;
    //权重矩阵
    double w1[inputnodes][hidenodes];
    double w2[hidenodes][outputnodes];
    //输出变量
    double output;
    //随机初始化权重矩阵
    for (int i = 0; i < inputnodes; i++) {
        for (int j = 0; j < hidenodes; j++) {
            w1[i][j] = (rand() / (RAND_MAX + 1.0)) - 0.5;
        }
    }
    for (int i = 0; i < hidenodes; i++) {
        for (int j = 0; j < outputnodes; j++) {
            w2[i][j] = (rand() / (RAND_MAX + 1.0)) - 0.5;
        }
    }
    const  int epochs = 50000; // 训练次数
    const double learnrate = 0.001; // 学习率
    //隐藏层的输出
    double hideoutput[hidenodes];
    for (int i = 0; i < epochs; i++) {
        for (int i = 0; i < hidenodes; i++) {
            double sum = 0;
            for (int j = 0; j < inputnodes; j++) {
                sum += input[j] * w1[j][i];
            }
            hideoutput[i] = 1.0 / (1.0 + exp(-sum));//sigmoid函数激活
        }
        double sum1 = 0;
        for (int i = 0; i < hidenodes; i++)
        {
            sum1 += hideoutput[i] * w2[i][0];
        }
        //sigmoid函数激活sum1;
        output = 1.0 / (1.0 + exp(-sum1));
        double error = pow(output - input[0], 2);//均方差误差
        if(i%1000==0)cout << "\nerror:" << error ;
        if (error < 0.01) {
            break;
        }
        //计算梯度,并更新权重
        double outputgrad;
        double hidegrad;
        //更新隐藏到输出层权重
        for (int i = 0; i < hidenodes; i++) {
            outputgrad = error * hideoutput[i];
            w2[i][0] -= learnrate * outputgrad;
            if (w2[i][0] < -1)w2[i][0] = -1;
            if (w2[i][0] > 1)w2[i][0] = 1;
        }
        //更新输入到隐藏层权重
        for (int j = 0; j < inputnodes; j++) { //遍历每个输入节点
            for (int i = 0; i < hidenodes; i++) {  //遍历每个隐藏节点
                hidegrad = error * w2[i][0] * hideoutput[i] * (1 - hideoutput[i]) * input[j];
                w1[j][i] -= learnrate * hidegrad;   //更新权重
                if (w1[j][i] < -1)w1[j][i] = -1;
                if (w1[j][i] > 1)w1[j][i] = 1;
            }
        }
    }
    //利用最终的权重预测传播
    double x[15];
    copy(Newcases, Newcases + 15, x);
    int max1=Preprocess(x, 15);

    for (int i = 0; i < hidenodes; i++) {
        double sum = 0;
        for (int j = 0; j < inputnodes; j++) {
            sum += Newcases[j] * w1[j][i];
        }
        hideoutput[i] = 1.0 / (1.0 + exp(-sum));//sigmoid函数
    }

    double sum1 = 0;
    for (int i = 0; i < hidenodes; i++)
    {
        sum1 += hideoutput[i] * w2[i][0];
    }
    output = 1.0 / (1.0 + exp(-sum1));

     Forecastcases = round(Postprocess(output, x, 15,max1));
}
int Epidemic::getForecastcases() {
    return Forecastcases;
}
int Epidemic::getNewcases(int k){
    return Newcases[k];
}
int Epidemic::getExistcases(int k){
    return Existcases[k];
}
int Epidemic::getAcumulatedcases(int k){
    return Acumulatedcases[k];
}
int Epidemic::getCuredcases(int k){
    return Curedcases[k];
}
int Epidemic::getDeathcases(int k){
    return Deathcases[k];
}

string Epidemic::getcity() {
    return city;
}
string Epidemic::getcountry() {
    return country;
}
void Epidemic::show(int n) const{
    cout<<"\t\t\t"<<setw(8)<<left<<country<<setw(14)<<city<<setw(12)<<Newcases[n]<<setw(12)<<Existcases[n]<<setw(12)<<Acumulatedcases[n]<<setw(12)<<Curedcases[n]<<setw(12)<<Deathcases[n]<<endl;
}

void Epidemic::setdates(int n,string country0, string city0, int Newcases0, int Existcases0, int Acumulatedcases0,
                       int Curedcases0, int Deathcases0) {
    country=country0;
    city=city0;
    Newcases[n]=Newcases0;
    Existcases[n]=Existcases0;
    Acumulatedcases[n]=Acumulatedcases0;
    Curedcases[n]=Curedcases0;
    Deathcases[n]=Deathcases0;
}

