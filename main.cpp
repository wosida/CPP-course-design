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
    //�����뷽ʽ�������ļ�
    ifstream numin("D:\\cppkeshe\\num.txt", ios::in);
    //�ж��ļ��Ƿ�򿪳ɹ�
    if (!numin) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        system("pause");
        return 1;
    }
    //��ȡ�ļ��е�����
    numin >> n;
//�ر��ļ�
    numin.close();
    vector<Epidemic> Epidemic(n);
    //�����뷽ʽ�������ļ�
    ifstream filein("D:\\cppkeshe\\data.txt", ios::in);
    //�ж��ļ��Ƿ�򿪳ɹ�
    if (!filein) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        system("pause");
        return 1;
    }
    //��ȡ�ļ��е����ݣ���Ϊ��˽�����ݳ�Ա���޷�ֱ�Ӷ��룬������Ӧ������Ϊ�βΣ�ͨ�����еĺ������и�ֵ
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
    //�ر��ļ�
    filein.close();
    cout<<"Ϊ������ʾ���ɽ�������󻯣�"<<endl;
    system("pause");
    string cityy;
    int flag1=0;
    string a;
    int count=0;
    while (1) {
        system("cls");
        i = Menu();
        switch (i) {
            //��ӳ��й���
            case 1:
                  system("cls");
                  addcity(&n,Epidemic);
                  system("pause");
                break;
            //��ӡ����
            case 2:
                system("cls");
                print(n,Epidemic);
                system("pause");
                break;
            //�޸Ĺ���
            case 3:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\t��ѡ���޸ķ�ʽ��"<<endl;
                cout<<"\t\t\t\t\t1.�������޸�"<<endl;
                cout<<"\t\t\t\t\t2.�������޸�"<<endl<<"\t\t\t";
                int k;
                cin>>k;
                while(1){
                    if(k!=1&&k!=2){
                        cout<<"\t\t\t�����������������룺";
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
            //ɾ������
            case 4:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\t��ѡ��ɾ����ʽ��"<<endl;
                cout<<"\t\t\t\t\t1.������ɾ��"<<endl;
                cout<<"\t\t\t\t\t2.������ɾ��"<<endl<<"\t\t\t";
                int m;
                cin>>m;
                while(1){
                    if(m!=1&&m!=2){
                        cout<<"\t\t\t�����������������룺";
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
                //ͳ�ƹ���
            case 5:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t��ѡ��ͳ�ƹ��ܣ�������������������Ϊ׼����"<<endl;
                cout<<"\t\t\t\t\t1.��������������"<<endl;
                cout<<"\t\t\t\t\t2.���ִ没������"<<endl;
                cout<<"\t\t\t\t\t3.���ۼƲ�������"<<endl;
                cout<<"\t\t\t\t\t4.��������������"<<endl;
                cout<<"\t\t\t\t\t5.��������������"<<endl;
                cout<<"\t\t\t\t\t6.��ѯĳ�����ۼ���������"<<endl<<"\t\t\t";
                int p;
                cin>>p;
                while(1){
                    if(p!=1&&p!=2&&p!=3&&p!=4&&p!=5&&p!=6){
                        cout<<"\t\t\t�����������������룺";
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
                //Ԥ�⹦��
            case 6:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\t����������ҪԤ��ĳ��У�";
                cin>>cityy;
                cout<<"\t\t\t********************************************************\n";
                cout<<"\t\t\t�ó���ǰʮ�����ÿ�������ǰһ����������������£�\n"<<endl;
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
                    cout<<"\n\t\t\tδ�ҵ��ó��У�"<<endl;
                    system("pause");
                }
               if(flag1==1){
                   cout<<"\n\n\n\n\t\t\t�ó��е���Ԥ�������������Ϊ��"<<Epidemic[count].getForecastcases()<<endl;
                   system("pause");
               }
                break;
            //���湦��
            case 7:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\tȷ�����棿����1/��2��"<<endl;
                cout<<"\t\t\t********************************************************\n\t\t\t\t\t";
                int b;
                cin>>b;
                while(1){
                    if(b!=1&&b!=2){
                        cout<<"\t\t\t�����������������룺";
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
                    cout<<"\t\t\t\t\t��ȡ������"<<endl;
                    cout<<"\t\t\t********************************************************\n\t\t\t\t\t";
                }
                break;
            //��������
            case 0:
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t********************************************************\n";
                cout<<"\t\t\t\t\tSure to exit?(��yes��or��no��)"<<endl;
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
                cout<<"\n\t\t\t\t\t������������������:";
                cin>>i;
                break;
        }
    }
}

