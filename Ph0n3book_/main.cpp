#include<bits/stdc++.h>
using namespace std;
template<typename vartype>
struct linked_list{

	// N O D E 

	struct node{
		vartype data;
		node *addr3ss;
		node(){addr3ss = NULL;}
		node(vartype val){data = val;addr3ss = NULL;}
	}*root = NULL,*last = NULL;
	
	//  I N S E R T

	void insert(vartype data){
		if(root == NULL){
			root = new node(data);
			last = root;
		}
		else{
			last->addr3ss = new node(data);
			last = last->addr3ss;
		}
	}

	// D E L E T E

	void del(vartype data){
		if(root != NULL){
			node *current = root;
			node *prev = NULL;
			while(current->data!=data){
				prev = current;
				current = current->addr3ss;
				if(current == last)break;
			}
			if(current->data == data){
				if(current == root)delete(root);
				else{
					prev->addr3ss = current->addr3ss;
					delete(current);
				}
			}
			else cout<<"DATA NOT FOUND"<<endl;
		}
		else cout<<"NO THING TO DELETE"<<endl;
	}

	// S E A R C H

	node * search(vartype data){
		node *current = root;
		while(current->data!=data){
			current = current->addr3ss;
			if(current == last)break;
		}
		if(current->data == data)return current;
		else return NULL;
	}

	// S H O W

	void show(){
		for(auto i = root;i!=last->addr3ss;i=i->addr3ss)
			cout<<i->data.first<<"  "<<i->data.second<<endl;
	}

	// U P D A T E 

	void update(vartype update,vartype exist){
		node *current = root;
		node *prev = NULL;
		while(current->data != exist){
			//prev = current;
			current = current->addr3ss;
			if(current == last)break;
		}
		if(current->data == exist){
			//node * newNode = new node(update);
			//newNode->addr3ss = current->addr3ss;
			current->data = update;
			//delete(current);
		}
		else cout<<"DATA NOT FOUND"<<endl;
	}

};

// M A I N   F U N C T I O N

int main(){
	string s = ".....................";
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	linked_list<pair<string,string>>list;
	string command;
	while(cin>>command){
		string name,phone;
		if(command == "INSERT"){
			cout<<endl<<"  AFTER INSERT"<<endl<<endl;
			while(true){
				cin>>name;
				if(name == "FINISH")break;
				cin>>phone;
				//auto temp = list.search({name,phone});
				list.insert({name,phone});
				//else cout<<name<<" "<<phone<<" ALREADY IN LIST "<<endl;
			}
			list.show();
			cout<<endl<<s<<endl;
		}
		else if(command == "DEL"){
			cout<<endl<<"  AFTER DELETE"<<endl<<endl;
			cin>>name>>phone;
			list.del({name,phone});
			list.show();
			cout<<endl<<s<<endl;
		}
		else if(command == "SEARCH"){
			cout<<endl<<"  AFTER SEARCH"<<endl<<endl;
			cin>>name>>phone;
			auto found = list.search({name,phone});
			if(found!=NULL){
				cout<<"DATA FOUND : ";
				cout<<found->data.first<<" "<<found->data.second<<endl;
			}
			else cout<<"DATA NOT FOUND"<<endl;
			cout<<endl<<s<<endl;
		}
		else if(command == "UPDATE"){
			string uname,uphone;
			cin>>uname>>uphone>>name>>phone;
			//cout<<uname<<uphone<<name<<phone<<endl;
			list.update({uname,uphone},{name,phone});
			cout<<endl<<"   AFTER UPDATE"<<endl<<endl;
			list.show();
			cout<<endl<<s<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}