#include<bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;
typedef pair<float, int> ii;
class Graph{
	int n,m;
	vector <ii > A[100005];
	public:
		Graph(){
			n=0,m=0;
			A[0].push_back({0,0}); 
		}
		int getnumv(){
			return n;
		}
		void InsertEdge(int s, int d, float w){
			cout << "\n============Edge============="; 
		    int dem=0,tempv;
		    float tempw;
		    for (auto it = A[s].begin(); it!=A[s].end(); it++)
		    {
		        tempv = it->second;
		        tempw = it->first;
		        if(tempv==d){
		            dem = 1;
		            break;
				}
		    }
			if(dem==1) cout<<"\n Da co khong the them"; 
			else{
			 	A[s].push_back({w,d});     
			 	A[d].push_back({w,s});     
			 	cout<<"\nthem ts thanh cong";
				}
		}

		void InsertVertex(int s)
		{
			cout << "\n============Vertex=============";
			if(s>=0&&s<n)  
			cout<<"\n dinh da co trong do thi";  
			else
			  {
				for(int i=0;i<n;i++)  
				{ 
				  	float w;    
				  	cout<<"\nnhap trong so vao dinh ke thu "<<i<<": ";
					cin>>w; 
				  	if(w==0) continue;
					A[s].push_back({w,i});   
					A[i].push_back({w,s});  
				}
				cout<<"\n da them:";
			}
		}
		void GetWeight(int s, int d){
			cout << "\n============Weight=============";
			int temp;
			float w;
			int dem=0;
			
			for (auto it = A[s].begin(); it!=A[s].end(); it++)
		    {
		            temp = it->second;
		            w = it->first;
		            if(temp==d){
		            	dem++;
		            	cout << "\nDinh " << s << " noi voi dinh " << d << " co trong so: " << w;
		            	break;
					}
		    }
		    if(dem==0){
		    	cout << "Khong ton tai";
			}
		}
		void Print(){
			cout << "\n============Graph=============\n";
			int v;
			float w;
		    for (int i = 0; i < n; i++)
		    {
		        cout << "Dinh " << i << " Cap voi \n";
		        for (auto it = A[i].begin(); it!=A[i].end(); it++)
		        {
		            v = it->second;
		            w = it->first;
		            cout << "\tDinh " << v << " voi trong so = "
		                 << w << "\n";
		        }
		        cout << "\n";
		    }
		}
		void nhap(){
			ifstream ifs("file.txt");
			if(ifs.fail()){
				cout << "File hong xin cam on!" << endl;
			}
			ifs >> n >> m;
			for(int i=0;i<m;i++){
				int s,d;
				float w;
				ifs >> s >> d >> w;
				A[s].push_back({w,d});
				A[d].push_back({w,s});
			}
			ifs.close();
			cout << "Lay thanh cong!";
		}
		void dijsktra(int src, int dest)
		{
		    priority_queue< ii, vector <ii> , greater<ii> > pq;
		    vector<int> dist(n, INF);
		    pq.push(make_pair(0, src));
		    dist[src] = 0;
		    while (!pq.empty())
		    {
		        int u = pq.top().second;
		        pq.pop();
		        for (auto x : A[u])
		        {
		            int v = x.second;
		            int weight = x.first;
		            if (dist[v] > dist[u] + weight)
		            {
		                dist[v] = dist[u] + weight;
		                pq.push(make_pair(dist[v], v));
		            }
		        }
		    }
		    printf("Nguon / Dich / Khoang cach\n");
		    printf("%d \t %d \t %d\n",src, dest, dist[dest]);
		}
};

int main(){
	Graph *a;
	a=new Graph;
	int chon;
	int td, tc, tt;
	int d;
	do{
		cout << "\n1. Read file.\n";
		cout << "2. Xuat do thi.\n";
		cout << "3. Them mot cung vao do thi\n";
		cout << "4. Them dinh vao do thi\n";
		cout << "5. Lay trong so tu do thi\n";
		cout << "6. Su dung thuat toan dijsktra\n";
		cout << "0. Thoat\n";
		cout << "Moi ban nhap: ";
		cin >> chon;
		switch(chon){
			case 1:{
				a->nhap();
				break;
			}
			case 2:{
				a->Print();
				break;
			}
			case 3:{
				cout << "Nhap lan luot dinh dau dinh cuoi va trong so: ";
				cin >> td >> tc >> tt;
				a->InsertEdge(td,tc,tt);
				break;
			}
			case 4:{
				cout << "Nhap dinh ban muon them vao do thi:";
				cin >> d;
				a->InsertVertex(d);
				break;
			}
			case 5:{
				cout << "Nhap dinh dau va dinh cuoi de lay trong so: ";
				cin >> td >> tc;
				a->GetWeight(td,tc);
				break;
			}
			case 6:{
				cout << "Nhap dinh dau va dinh cuoi de tim duong di ngan nhat: ";
				cin >> td >> tc;
				a->dijsktra(td,tc);
				break;
			}
			case 0:{
				return 0;
				break;
			}
		}
		
	}
	while(chon>=1 && chon<=6);

	return 0;
}
