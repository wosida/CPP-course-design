//
// Created by 李冬阳 on 2023/5/25.
//
#include"class.h"

//菜单函数
int   Menu()
{
    int i;
    system("title 疫情统计与预测系统V1.0");
    cout<<"\n\n";
    cout<<"\t\t\t                  疫情统计与预测系统V1.0\n";
    cout<<"\t\t\t******************************************************\n";
    cout<<"\t\t\t*                 疫情统计与预测系统                 *\n";
    cout<<"\t\t\t*                   1. 添加城市                      *\n";
    cout<<"\t\t\t*                   2. 打印功能                      *\n";
    cout<<"\t\t\t*                   3. 修改功能                      *\n";
    cout<<"\t\t\t*                   4. 删除功能                      *\n";
    cout<<"\t\t\t*                   5. 统计功能                      *\n";
    cout<<"\t\t\t*                   6. 预测功能                      *\n";
    cout<<"\t\t\t*                   7. 保存功能                      *\n";
    cout<<"\t\t\t*                   0. 退出系统                      *\n";
    cout<<"\t\t\t******************************************************\n";
    cout<<"\n\n\n\n";
    cout<<"\t基础数据已从文件读入，您可选择继续添加城市，也可直接测试其他功能...\n";
    cout<<"\t\t\t*****************Please Input your choice:";
    cin>>i;
    return i;
}
//打印函数,打印现存城市信息
void print(int n,vector<Epidemic> Epidemic1){
    cout<<"\n\n\n\n\n\n\t\t\t********************************************************************************************\n";
    cout<<"\t\t\t请选择查看哪一天的疫情数据(1-30)：";
    int i;////┌─│┐└┘│


    cin>>i;
    system("cls");
    cout<<"\t\t*********************************************************************************************\n";
            cout<<"\t\t\t\t\t\t\t现存城市信息如下："<<endl;
    cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
            cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
            for(int j=0;j<n;j++){
                cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
                Epidemic1[j].show(i-1);
            }
            cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
    cout<<"\t\t*********************************************************************************************\n";
}
//增添城市函数，注意传入的是地址和引用，否则无法在Epidemic中添加元素
void addcity(int *n,vector<Epidemic> &Epidemic1){
    int n1;
    int p=0;
    cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
    cout<<"\t\t\t\t\t请输入您想要增添城市的个数：";
    cin>>n1;
    getchar();
    if(n1<=0){
        cout<<"\t\t\t\t\t输入错误，请重新进入！"<<endl;
        return;
    }
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t****************************************************************************************\n";
    for(int j=0;j<n1;j++){
        int k=0;
           cout<<"\t\t\t请输入第"<<(j+1)<<"个城市的第"<<(k+1)<<"天的数据（依次输入国家，城市，新增病例数，现有病例数，累计病例数，治愈病例数，死亡病例数）："<<endl<<"\t\t\t";
            Epidemic epidemic;
            string country;
            string city;
            int Newcases;
            int Existcases;
            int Acumulatedcases;
            int Curedcases;
            int Deathcases;
            cin >> country >> city >> Newcases >> Existcases >> Acumulatedcases >> Curedcases >> Deathcases;
            //如果城市重名，则提示重新输入
            for(int i=0;i<*n;i++){
                if(Epidemic1[i].getcity()==city){
                    p=1;
                    cout<<"\t\t\t该城市已存在，请重新输入！"<<endl;
                    j--;
                    break;
                }
            }
            if(p==1){
                p=0;
                continue;
            }
            epidemic.setdates(k, country, city, Newcases, Existcases, Acumulatedcases, Curedcases, Deathcases);
            Epidemic1.push_back(epidemic);
            cout << "\t\t\t当前城市第"<<(k+1)<<"天数据添加成功，是否继续添加？（1/0）（不添加其他天数的疫情数据自动设为0）：";
            int m;
            while(1){
                cin >> m;
                if(m==1||m==0){
                    break;
                }
                else{
                    cout<<"\t\t\t输入错误，请重新输入！"<<endl;
                }
            }
            if (m == 0) {
                break;
            }
            if(m==1){
                while(1) {
                    k++;
                    cout << "\t\t\t请继续输入第" << (k + 1) << "天的数据（依次输入国家，城市，新增病例数，现有病例数，累计病例数，治愈病例数，死亡病例数）："
                         << endl << "\t\t\t";
                    cin >> country >> city >> Newcases >> Existcases >> Acumulatedcases >> Curedcases >> Deathcases;
                    epidemic.setdates(k, country, city, Newcases, Existcases, Acumulatedcases, Curedcases, Deathcases);
                    Epidemic1.pop_back();
                    Epidemic1.push_back(epidemic);
                    cout<<"\t\t\t当前城市第"<<(k+1)<<"天数据添加成功，是否继续添加？（1/0）：";
                    int t;
                    while(1){
                        cin >> t;
                        if(t==1||t==0){
                            break;
                        }
                        else{
                            cout<<"\t\t\t输入错误，请重新输入！"<<endl;
                        }
                    }
                    if(t==0){
                        break;
                    }
                }
            }
    }
    *n+=n1;
}
//删除城市信息功能函数
void deletecity(int *n,vector<Epidemic> &Epidemic1){
    int n1;
    int n2;//实际删除的城市个数
    cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
    cout<<"\t\t\t\t\t请输入您想要删除城市的个数：";
    cin>>n1;
    n2=n1;
    getchar();
    if(n1<=0){
        cout<<"\t\t\t\t\t输入错误，请重新进入！"<<endl;
        return;
    }
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t****************************************************************************************\n";
    cout<<"\t\t\t请输入各个城市名称：";
    string city1[n1];
    int flag=0;//判断是否有该城市

    vector<int> positions(0);//记录要删除的城市在Epidemic1中的位置
    for(int j=0;j<n1;j++){
        cin>>city1[j];
    }
    cout<<"\n\n\n\n\n\n\t\t*********************************************************************************************\n";
    cout<<"\t\t\t\t\t\t搜寻到各城市疫情信息如下（最新一天数据）：\n";
    cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
    cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
    for(int i=0;i<n1;i++) {
        for (int j = 0; j < *n; j++) {
            if (Epidemic1[j].getcity() == city1[i]) {
                flag=1;
                cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
                Epidemic1[j].show(0);

                positions.push_back(j);//将要删除的城市在Epidemic1中的位置存入position数组中
                break;
            }
        }

        if(flag==0){
        cout<<"\t\t\t未查询到城市"<<city1[i]<<"的信息！"<<endl;
        n2--;//如果未查询到城市信息，则实际删除的城市个数减一
        }
        flag=0;//flag重新置为0，确保在每一次循环过程中进入if语句前flag都是0
    }
    cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
    cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
    cout<<"\t\t\t*********************************************************************************************\n";
    if(n2==0){
    system("pause");}//如果未查询到城市信息，则不执行删除操作
    if(n2>0) {
        cout << "\t\t\t是否确定全部删除？（1.是 2.否）";
        int i;
        cin >> i;
        if (i == 1) {
            sort(positions.begin(),positions.end());//将positions数组从小到大排序，便于删除
            auto end_unique=unique(positions.begin(),positions.end());//unique函数将重复元素放到数组的末尾，并返回指向第一个重复元素的迭代器
            positions.erase(end_unique,positions.end());//删除重复元素
            for(int j=0;j<positions.size();j++) {
                Epidemic1.erase(Epidemic1.begin() + positions[j] - j);//因为删除一个元素后，后面的元素会向前移动，所以要减去j
            }
            *n-=n2;
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t****************************************************************************************\n";
            cout<<"\t\t\t\t\t\t\t\t删除成功！"<<endl;
            cout<<"\t\t\t****************************************************************************************\n";
            system("pause");
        }
        if (i == 2) {
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t****************************************************************************************\n";
            cout<<"\t\t\t\t\t\t\t\t删除失败！"<<endl;
            cout<<"\t\t\t****************************************************************************************\n";
            system("pause");
            return;
        }
    }

}
//删除国家疫情信息功能函数
void deletecountry(int *n,vector<Epidemic> &Epidemic1){
    int n1,n2=0;//n1记录有多少个国家，n2记录要删除的城市的个数
    cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
    cout<<"\t\t\t\t\t请输入您想要删除国家的个数：";
    cin>>n1;
    getchar();
    if(n1<=0){
        cout<<"\t\t\t\t\t输入错误，请重新进入！"<<endl;
        return;
    }
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t****************************************************************************************\n";
    cout<<"\t\t\t请输入各个国家名称：";
    string country1[n1];//字符串数组，记录n1个国家的名称
    vector <int> positions(0);//定义一个变长数组，便于记录每个城市在原来Epidemic向量中的位置
    int flag=0;
    for(int j=0;j<n1;j++){
        cin>>country1[j];
    }
    cout<<"\n\n\n\n\n\n\t\t*********************************************************************************************\n";
    cout<<"\t\t\t\t\t\t搜寻到的国家中疫情信息如下：(最新一天数据）"<<endl;
    cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
    cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
    for(int i=0;i<n1;i++) {
        for (int j = 0; j < *n; j++) {
            if (Epidemic1[j].getcountry() == country1[i]) {
                flag=1;
                cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
                Epidemic1[j].show(0);
                positions.push_back(j);//可变长数组的好处，不需要提前定义数组的长度，也不需要像上个函数一样定义一个m变量来记录位置
                n2+=1;//这个循环不可break；因为相同国家城市有很多
            }
        }
        if(flag==0){
            cout<<"\t\t\t未查询到"<<country1[i]<<"的疫情信息！"<<endl;
        }
        flag=0;
    }
    cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
    cout<<"\t\t*********************************************************************************************\n";
    if(n2==0){
        system("pause");
    }//如果未查询到城市信息，则不执行删除操作
    if(n2>0){
    cout<<"\t\t\t是否确定全部删除？（1.是 2.否）";
        int i;
        cin>>i;
        if(i==1){
            sort(positions.begin(),positions.end());//将positions数组从小到大排序，便于删除
            auto end_unique=unique(positions.begin(),positions.end());//unique函数将重复元素放到数组的末尾，并返回指向第一个重复元素的迭代器
            positions.erase(end_unique,positions.end());//删除重复元素
            for(int j=0;j<positions.size();j++){
                Epidemic1.erase(Epidemic1.begin()+positions[j]-j);//因为删除一个元素后，后面的元素会向前移动，所以要减去j
            }
            *n-=n2;
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t****************************************************************************************\n";
            cout<<"\t\t\t\t\t\t\t\t\t删除成功！"<<endl;
            cout<<"\t\t\t****************************************************************************************\n";
            system("pause");
        }
        if(i==2){
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t****************************************************************************************\n";
            cout<<"\t\t\t\t\t\t\t\t删除失败！"<<endl;
            cout<<"\t\t\t****************************************************************************************\n";
            system("pause");
            return;
        }
    }
}
//修改城市疫情信息功能函数
void modifycity(int n,vector<Epidemic> &Epidemic1){
    cout<<"\n\n\n\n\n\n\t\t\t***********************************************************************************************\n";
    cout<<"\t\t\t\t\t请输入您想要修改的城市名称：";
    getchar();
    string city1;
    cin>>city1;
    int flag=0;
    int m;
    int i;
    string country2, city2;
    int new1, now1, total1, cure1, die1;
    cout<<"\t\t\t***********************************************************************************************\n";
    for( i=0;i<n;i++) {
        if (Epidemic1[i].getcity() == city1) {
            flag=1;
            cout << "\t\t\t\t\t\t\t搜寻到城市疫情信息如下：（最新一天数据）" << endl;
            cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
            cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
            Epidemic1[i].show(0);
            cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
            cout << "\t\t\t***********************************************************************************************\n";
            cout<<"请输入想要修改哪一天的数据？(1-30)";
            cin>>m;
            while(m<1||m>30){
                cout<<"输入错误，请重新输入！"<<endl;
                cin>>m;
            }
            system("cls");
            cout << "\n\n\n\t\t\t***********************************************************************************************\n";
            cout<<"\t\t\t\t\t搜寻到城市疫情信息如下：（第"<<m<<"天数据）" << endl;
            cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
            Epidemic1[i].show(m-1);
            cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
            cout << "\t\t\t请输入修改后的城市疫情信息：(国家，城市，新增病例数，现有病例数，累计病例数，治愈病例数，死亡病例数)" << endl<<"\t\t\t";
            cin >> country2 >> city2 >> new1 >> now1 >> total1 >> cure1 >> die1;
            getchar();
            break;
        }
    }
    if(flag==0){
        cout<<"\t\t\t未查询到"<<city1<<"的疫情信息！"<<endl;
        system("pause");
    return;}
    cout<<"\t\t\t*********************************************************************************************\n";
    int k;
    cout<<"\t\t\t是否确定修改？（1.是 2.否）";
    while(1){
        cin>>k;
        if(k==1||k==2){
            break;
        }
        else{
            cout<<"\t\t\t输入错误，请重新输入:";
        }
    }
    if(k==1) {
        system("cls");
        Epidemic1[i].setdates(m-1,country2,city2,new1,now1,total1,cure1,die1);
        cout << "\n\n\n\n\n\n\t\t\t***********************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t\t\t修改成功！" << endl;
        cout<<"\t\t\t***********************************************************************************************\n";
        system("pause");
    }
    if(k==2){
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t***********************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t修改失败！" << endl;
        cout<<"\t\t\t***********************************************************************************************\n";
        system("pause");
    }
}
//修改国家疫情信息功能函数
void modifycountry(int *n,vector<Epidemic> &Epidemic1) {
    cout << "\n\n\n\n\n\n\t\t\t********************************************************\n";
    cout << "\t\t\t\t\t请输入您想要修改的国家名称：";
    int flag = 0;
    vector<int> positions(0);
    string country1;
    cin >> country1;
    getchar();
    cout << "\t\t********************************************************************************************\n";
    cout << "\t\t\t搜寻到国家疫情信息如下：（各城市均是最新一天的数据）" << endl;
    cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
    cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;

    for (int i = 0; i < *n; i++) {
        if (Epidemic1[i].getcountry() == country1) {
            flag = 1;
            cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
            Epidemic1[i].show(0);
            positions.push_back(i);
        }
    }
    if (flag == 0) {
        cout << "\t\t\t未查询到" << country1 << "的疫情信息！" << endl;
        system("pause");
        return;
    }
    cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
    cout << "\t\t********************************************************************************************\n";
    cout << "\t\t\t请输入修改后的国家疫情信息包含的城市数：";
    int g;
    cin >> g;
    cout << "\t\t\t请输入修改后的国家疫情信息：(国家，城市，新增病例数，现有病例数，累计病例数，治愈病例数，死亡病例数)(1-30天)"
         << endl;

    for (int i = 0; i < g; i++) {
        cout << "\t\t\t第" << (i + 1) << "个城市：" << endl << "\t\t\t";
        for (int j = 0; j < 30; j++) {
            int k = 0;
            Epidemic Epidemic2;
            string country2, city2;
            int new1, now1, total1, cure1, die1;
            cin >> country2 >> city2 >> new1 >> now1 >> total1 >> cure1 >> die1;
            getchar();
            Epidemic2.setdates(k, country2, city2, new1, now1, total1, cure1, die1);
            Epidemic1.push_back(Epidemic2);
            cout << "\t\t\t当前城市第" << (k + 1) << "天数据添加成功，是否继续添加？（1/0）：";
            int m;
            while (1) {
                cin >> m;
                if (m == 1 || m == 0) {
                    break;
                } else {
                    cout << "\t\t\t输入错误，请重新输入！" << endl;
                }
            }
            if (m == 0) {
                break;
            }
            int t;
            if (m == 1) {
                while (1) {
                    k++;
                    cout << "\t\t\t请继续输入该城市第" << (k + 1) << "天的数据（依次输入国家，城市，新增病例数，现有病例数，累计病例数，治愈病例数，死亡病例数）："
                         << endl << "\t\t\t";
                    cin >> country2 >> city2 >> new1 >> now1 >> total1 >> cure1 >> die1;
                    getchar();
                    Epidemic2.setdates(k, country2, city2, new1, now1, total1, cure1, die1);
                    Epidemic1.pop_back();
                    Epidemic1.push_back(Epidemic2);
                    cout << "\t\t\t当前城市第" << (k + 1) << "天数据添加成功，是否继续添加？（1/0）：";
                    while (1) {
                        cin >> t;
                        if (t == 1 || t == 0) {
                            break;
                        } else {
                            cout << "\t\t\t输入错误，请重新输入！" << endl << "\t\t\t";
                        }
                    }
                    if (t == 0) {
                        break;
                    }
                }
            }
            if (t == 0) {
                break;
            }
        }
    }
        cout << "\t\t\t*********************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t确认修改？（1/0）" ;
        int p;
        cin >> p;
        if (p == 1) {
            *n = *n + g-positions.size();
            sort(positions.begin(), positions.end());//将positions数组从小到大排序，便于删除
            auto end_unique = unique(positions.begin(), positions.end());//unique函数将重复元素放到数组的末尾，并返回指向第一个重复元素的迭代器
            positions.erase(end_unique, positions.end());//删除重复元素
            for (int j = 0; j < positions.size(); j++) {
                Epidemic1.erase(Epidemic1.begin() + positions[j] - j);//因为删除一个元素后，后面的元素会向前移动，所以要减去j
            }
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t*********************************************************************************************\n";
            cout << "\t\t\t\t\t\t修改成功！" << endl;
            cout << "\t\t\t*********************************************************************************************\n";
            system("pause");
        }
        if (p == 0) {
            for (int j = 0; j < g; j++) {
                Epidemic1.pop_back();
            }
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t*********************************************************************************************\n";
            cout << "\t\t\t修改失败！" << endl;
            cout << "\t\t\t*********************************************************************************************\n";
            system("pause");
        }
    }
//按照新增病例数排序函数
    bool cmp1(Epidemic a, Epidemic b) {
        return a.getNewcases(0) < b.getNewcases(0);
    }
    void sortbyNewcases(int n, vector<Epidemic> Epidemic1) {
        cout
                << "\n\n\n\n\n\n\t\t**************************************************************************************************\n";
        cout << "\t\t\t按照新增病例数排序后的国家疫情信息如下：（各城市均是最新一天的数据）" << endl;////┌─│┐└┘─────────


        cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
        sort(Epidemic1.begin(), Epidemic1.end(), cmp1);
        for (int i = 0; i < n; i++) {
            cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
            Epidemic1[i].show(0);
        }
        cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
        cout << "\t\t************************************************************************************************\n";
        system("pause");
    }
//按照现有病例数排序函数
    bool cmp2(Epidemic a, Epidemic b) {
        return a.getExistcases(0) < b.getExistcases(0);
    }
    void sortbyExistcases(int n, vector<Epidemic> Epidemic1) {
        cout
                << "\n\n\n\n\n\n\t\t************************************************************************************************\n";
        cout<<"\t\t\t按照现有病例数排序后的国家疫情信息如下：（各城市均是最新一天的数据）"<<endl;
        cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
        sort(Epidemic1.begin(), Epidemic1.end(), cmp2);
        for (int i = 0; i < n; i++) {
            cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
            Epidemic1[i].show(0);
        }
        cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
        cout << "\t\t************************************************************************************************\n";
        system("pause");
    }
//按照累计病例数排序函数
    bool cmp3(Epidemic a, Epidemic b) {
        return a.getAcumulatedcases(0) < b.getAcumulatedcases(0);
    }
    void sortbyAcumulatedcases(int n, vector<Epidemic> Epidemic1) {
        cout
                << "\n\n\n\n\n\n\t\t\t**********************************************************************************\n";
        cout << "\t\t\t按照累计病例数排序后的国家疫情信息如下：（各城市均是最新一天的数据）" << endl;
        cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
        sort(Epidemic1.begin(), Epidemic1.end(), cmp3);
        for (int i = 0; i < n; i++) {
            cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
            Epidemic1[i].show(0);
        }
        cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
        cout << "\t\t\t**********************************************************************************\n";
        system("pause");
    }
//按照治愈病例数排序函数
    bool cmp4(Epidemic a, Epidemic b) {
        return a.getCuredcases(0) < b.getCuredcases(0);
    }
    void sortbyCuredcases(int n, vector<Epidemic> Epidemic1) {
        cout
                << "\n\n\n\n\n\n\t\t************************************************************************************************\n";
        cout << "\t\t\t按照治愈病例数排序后的国家疫情信息如下：（各城市均是最新一天的数据）" << endl;
        cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
        sort(Epidemic1.begin(), Epidemic1.end(), cmp4);
        for (int i = 0; i < n; i++) {
            cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
            Epidemic1[i].show(0);
        }
        cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
        cout << "\t\t************************************************************************************************\n";
        system("pause");
    }
//按照死亡病例数排序函数
    bool cmp5(Epidemic a, Epidemic b) {
        return a.getDeathcases(0) < b.getDeathcases(0);
    }
    void sortbyDeathcases(int n, vector<Epidemic> Epidemic1) {
        cout<< "\n\n\n\n\n\n\t\t************************************************************************************************\n";
        cout << "\t\t\t按照死亡病例数排序后的国家疫情信息如下：（各城市均是最新一天的数据）" << endl;
        cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
        sort(Epidemic1.begin(), Epidemic1.end(), cmp5);
        for (int i = 0; i < n; i++) {
            cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
            Epidemic1[i].show(0);
        }
        cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
        cout << "\t\t************************************************************************************************\n";
        system("pause");
    }
//查看某国家疫情信息函数
    void searchbyCountry(int n, vector<Epidemic> Epidemic1) {
        string country;
        cout
                << "\n\n\n\n\n\n\t\t************************************************************************************************\n";
        cout << "\t\t\t请输入您要查询的国家：";
        cin >> country;
        int flag = 0;
        cout << "\t\t\t" << country << "累计疫情数据如下：" << endl;
        cout<<"\t\t       ┌────────────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"\t\t"<<setw(8)<<left<<"       │国家"<<setw(10)<<" │  城市"<<setw(12)<<"  │  新增病例数"<<setw(12)<<" │ 现有病例数"<<setw(12)<<" │ 累计病例数"<<setw(12)<<"│治愈病例数"<<setw(12)<<"│死亡病例数│"<<endl;
        for (int i = 0; i < n; i++) {
            if (Epidemic1[i].getcountry() == country) {
                flag = 1;
                cout<<"\t\t       │────────────────────────────────────────────────────────────────────────────│"<<endl;
                Epidemic1[i].show(0);
            }
        }
        if (flag == 0) {
            cout << "\t\t\t未查询到该国家疫情信息！" << endl;
        }
        cout<<"\t\t       └────────────────────────────────────────────────────────────────────────────┘"<<endl;
        cout << "\t\t************************************************************************************************\n";
        system("pause");
    }
//保存到txt文件函数
void save(int n, vector<Epidemic> Epidemic1) {
    ofstream fileout("D:\\cppkeshe\\data.txt", ios::out);
    if (!fileout) {
        cout << "\t\t\t文件打开失败！" << endl;
        exit(1);
    }
    for (int j=0;j<30;j++) {
        for (int i = 0; i < n; i++) {
            fileout << Epidemic1[i].getcountry() << " " << Epidemic1[i].getcity() << " " << Epidemic1[i].getNewcases(j)
                    << " " << Epidemic1[i].getExistcases(j) << " " << Epidemic1[i].getAcumulatedcases(j) << " "
                    << Epidemic1[i].getCuredcases(j) << " " << Epidemic1[i].getDeathcases(j) << endl;
        }
    }
    fileout.close();
    ofstream numout("D:\\cppkeshe\\num.txt", ios::out);
    if (!numout) {
        cout << "\t\t\t文件打开失败！" << endl;
        exit(1);
    }
    numout << n;
    numout.close();
    cout << "\t\t\t保存成功！" << endl;
    system("pause");
}
