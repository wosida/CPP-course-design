#include "class.h"

int Menu();
void print(int n,vector<Epidemic> Epidemic);
void addcity(int *n,vector<Epidemic> &Epidemic);
void deletecountry(int *n,vector <Epidemic> &Epidemic1);
void deletecity(int *n,vector<Epidemic> &Epidemic1);
void modifycity(int n,vector<Epidemic> &Epidemic1);
void modifycountry(int *n,vector<Epidemic> &Epidemic1);
void sortbyNewcases(int n,vector<Epidemic> Epidemic1);
void sortbyExistcases(int n,vector<Epidemic> Epidemic1);
void sortbyAcumulatedcases(int n,vector<Epidemic> Epidemic1);
void sortbyCuredcases(int n,vector<Epidemic> Epidemic1);
void sortbyDeathcases(int n,vector<Epidemic> Epidemic1);
void searchbyCountry(int n,vector<Epidemic> Epidemic1);
void save(int n, vector<Epidemic> Epidemic1);
int main() {
    system("color 8e");
    int i;
    int n;
    //以输入方式打开人数文件
    ifstream numin("D:\\cppkeshe\\num.txt", ios::in);
    //判断文件是否打开成功
    if (!numin) {
        cout << "文件打开失败！" << endl;
        system("pause");
        return 1;
    }
    //读取文件中的数据
    numin >> n;
//关闭文件
    numin.close();
    vector<Epidemic> Epidemic(n);
    //以输入方式打开数据文件
    ifstream filein("D:\\cppkeshe\\data.txt", ios::in);
    //判断文件是否打开成功
    if (!filein) {
        cout << "文件打开失败！" << endl;
        system("pause");
        return 1;
    }
    //读取文件中的数据，因为是私有数据成员，无法直接读入，定义相应变量作为形参，通过类中的函数进行赋值
    for(int m=0;m<30;m++) {
        for (int j = 0; j < n; j++) {
            string country;
            string city;
            int Newcases;
            int Existcases;
            int Acumulatedcases;
            int Curedcases;
            int Deathcases;
            filein >> country >> city >> Newcases >> Existcases >> Acumulatedcases >> Curedcases
                   >> Deathcases;
            Epidemic[j].setdates(m, country,city, Newcases, Existcases, Acumulatedcases, Curedcases,
                                 Deathcases);
        }
    }
    //关闭文件
    filein.close();
    cout<<"为方便显示，可将窗口最大化！"<<endl;
    system("pause");
    string cityy;
    int flag1=0;
    string a;
    int count=0;
    while (1) {
        system("cls");
        i = Menu();
        switch (i) {
            //添加城市功能
            case 1:
                  system("cls");
                  addcity(&n,Epidemic);
                  system("pause");
                break;
            //打印功能
            case 2:
                system("cls");
                print(n,Epidemic);
                system("pause");
                break;
            //修改功能
            case 3:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\t请选择修改方式："<<endl;
                cout<<"\t\t\t\t\t1.按国家修改"<<endl;
                cout<<"\t\t\t\t\t2.按城市修改"<<endl<<"\t\t\t";
                int k;
                cin>>k;
                while(1){
                    if(k!=1&&k!=2){
                        cout<<"\t\t\t输入有误，请重新输入：";
                        cin>>k;
                    } else{
                        break;
                    }
                }
                if(k==1){
                    system("cls");
                    modifycountry(&n,Epidemic);
                }
                if(k==2){
                    system("cls");
                    modifycity(n,Epidemic);
                }
                break;
            //删除功能
            case 4:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\t请选择删除方式："<<endl;
                cout<<"\t\t\t\t\t1.按国家删除"<<endl;
                cout<<"\t\t\t\t\t2.按城市删除"<<endl<<"\t\t\t";
                int m;
                cin>>m;
                while(1){
                    if(m!=1&&m!=2){
                        cout<<"\t\t\t输入有误，请重新输入：";
                        cin>>m;
                    } else{
                        break;
                    }
                }
                if(m==1){
                    system("cls");
                    deletecountry(&n,Epidemic);
                }
                if(m==2){
                    system("cls");
                    deletecity(&n,Epidemic);
                }
                break;
                //统计功能
            case 5:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t请选择统计功能（所有排序以最新数据为准）："<<endl;
                cout<<"\t\t\t\t\t1.按新增病例排序"<<endl;
                cout<<"\t\t\t\t\t2.按现存病例排序"<<endl;
                cout<<"\t\t\t\t\t3.按累计病例排序"<<endl;
                cout<<"\t\t\t\t\t4.按治愈病例排序"<<endl;
                cout<<"\t\t\t\t\t5.按死亡病例排序"<<endl;
                cout<<"\t\t\t\t\t6.查询某国家累计疫情数据"<<endl<<"\t\t\t";
                int p;
                cin>>p;
                while(1){
                    if(p!=1&&p!=2&&p!=3&&p!=4&&p!=5&&p!=6){
                        cout<<"\t\t\t输入有误，请重新输入：";
                        cin>>p;
                    } else{
                        break;
                    }
                }
                if(p==1){
                    system("cls");
                    sortbyNewcases(n,Epidemic);
                }
                if(p==2){
                    system("cls");
                    sortbyExistcases(n,Epidemic);
                }
                if(p==3){
                    system("cls");
                    sortbyAcumulatedcases(n,Epidemic);
                }
                if(p==4){
                    system("cls");
                    sortbyCuredcases(n,Epidemic);
                }
                if(p==5){
                    system("cls");
                    sortbyDeathcases(n,Epidemic);
                }
                if(p==6){
                    system("cls");
                    searchbyCountry(n,Epidemic);
                }
                break;
                //预测功能
            case 6:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\t请输入您想要预测的城市：";
                cin>>cityy;
                cout<<"\t\t\t********************************************************\n";
                cout<<"\t\t\t该城市前十五天的每天相对于前一天的新增病例数如下：\n"<<endl;
                cout<<"\t\t\t";
                for(int j=1;j<=15;j++){
                    cout<<setw(4)<<left<<"day-"<<setw(4)<<left<<j;
                }
                cout<<endl;
                for(int l=0;l<n;l++){
                    if(Epidemic[l].getcity()==cityy){
                        cout<<"\t\t\t  ";
                        flag1=1;
                        for(int j=0;j<15;j++){
                            cout<<setw(8)<<left<<Epidemic[l].getNewcases(j);
                        }

                        Epidemic[l].Forecast();
                        count=l;
                        break;
                    }
                }
                if(flag1==0){
                    cout<<"\n\t\t\t未找到该城市！"<<endl;
                    system("pause");
                }
               if(flag1==1){
                   cout<<"\n\n\n\n\t\t\t该城市当天预测新增病例结果为："<<Epidemic[count].getForecastcases()<<endl;
                   system("pause");
               }
                break;
            //保存功能
            case 7:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\t确定保存？（是1/否2）"<<endl;
                cout<<"\t\t\t********************************************************\n\t\t\t\t\t";
                int b;
                cin>>b;
                while(1){
                    if(b!=1&&b!=2){
                        cout<<"\t\t\t输入有误，请重新输入：";
                        cin>>b;
                    } else{
                        break;
                    }
                }
                if(b==1){
                    save(n,Epidemic);
                }
                if(b==2){
                    cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                    cout<<"\t\t\t\t\t已取消保存"<<endl;
                    cout<<"\t\t\t********************************************************\n\t\t\t\t\t";
                }
                break;
            //结束功能
            case 0:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\tSure to exit?(”yes“or“no”)"<<endl;
                cout<<"\t\t\t********************************************************\n\t\t\t\t\t";
                cin>>a;
                while (1) {
                    if (a!="yes"&&a!="no") {
                        cout<<"\n\n\n\t\t\tinput error!please input again:";
                        cin>>a;
                        getchar();
                    }
                    if (a=="yes"||a=="no") {
                        break;
                    }
                }
                if (a == "yes") {
                        system("cls");
                        cout << "\n\n\n\n\n\n\t\t\t********************************************************\n";
                        cout << "\t\t\t\t\tEnd of program!" << endl;
                        cout << "\t\t\t********************************************************\n";
                        getchar();
                        getchar();
                        return 0;
                } else if (a == "no") {
                        break;
                }
            default:
                cout<<"\n\t\t\t\t\t输入有误，请重新输入:";
                cin>>i;
                break;
        }
    }
}

