#include<iostream>
#include<set>
#include<map>
#include<cstdio>
using namespace std;

class User{

private:
	std::string name;
	int id;
	std::string email;
	std::set<int>groups;
	std::set<int>user_inivited_series;
	std::set<int>group_inivited_series;

public:
	User(int id,string name, string email){
		this->id = id;
		this->name = name;
		this->email = email;
	}

	User(int id){
		this->id = id;

	}

	User(){
		this->id = -1;
	}

	void printSeries(){
		 set<int>::iterator user_inivited_series_it; 

		 cout <<"SeriesId: ";
		 for (user_inivited_series_it = user_inivited_series.begin(); user_inivited_series_it!=user_inivited_series.end();  ++user_inivited_series_it){
        	cout <<*user_inivited_series_it << " ";
        }

        set<int>::iterator group_inivited_series_it;

		 for (group_inivited_series_it = group_inivited_series.begin(); group_inivited_series_it!=group_inivited_series.end();  ++group_inivited_series_it){
		 	user_inivited_series_it = user_inivited_series.find(*group_inivited_series_it);
		 	if(user_inivited_series_it == user_inivited_series.end())
        	cout <<*group_inivited_series_it << " ";
        }

        cout<<"\n";

	}

	void printGroups(){

		set<int>::iterator groups_it; 

		cout<<"UserId: ";
		 for (groups_it = groups.begin(); groups_it != groups.end();  ++groups_it){
        	cout <<*groups_it << " ";
        }

        cout<<"\n";
	
	}
	void printName(){
		cout<<"UserName: "<< name<<"\n";
	} 
	void printEmail(){
		cout<<"UserEmail: "<< email<<"\n";

	}
	string getEmail(){
		return email;
	}

	string getName(){
		return name;
	}

	void setName(string name){
		this->name = name;
	}

	void setEmail(string email){
		this->email = email;
	}

	void addInivitesSeries(int id){
		user_inivited_series.insert(id);

	}

	void addGroupInivitesSeries(int id){
		group_inivited_series.insert(id);
	}

	void addGroup(int id){
		groups.insert(id);
	}

	void deleteInivitesSeries(int id){
		if(user_inivited_series.find(id) != user_inivited_series.end()){
			user_inivited_series.erase(id);
		}
		else{
			cout<<"Series Id " << id <<"does not linked to User Id " <<this->id<<"\n";
		}
	}

	void deleteGroupInivitesSeries(int id){
		if(group_inivited_series.find(id) != group_inivited_series.end()){
			group_inivited_series.erase(id);
		}
		else{
			cout<<"Group invited Series Id "<<id<<" does not link User id  "<<this->id<<"\n";
		}
	}

	void deleteGroup(int id){
		if(groups.find(id) != groups.end()){
			groups.erase(id);
		}
		else{
			cout<<"Group Id "<<id<<" is not part of User Id "<<this->id<<"\n";
		}
	}

	set<int> groupsSet(){
		return groups;
	}

	set<int> userInvitedSeriesSet(){
		return user_inivited_series;
	}

	set<int> groupInvitedSeriesSet(){
		return group_inivited_series;
	}
	
};


class Series{

private:
	std::string name;
	int id;
	std::set<int>groups;
	std::set<int>users;

public:
	Series(int id,string name){
		this->id = id;
		this->name = name;
	}

	Series(int id){
		this->id = id;
	}

	Series(){
		this->id = -1;
	}

	void printName(){
		cout<<"UserName: "<<name<<"\n";
	} 

	string getName(){
		return name;
	}

	void setName(string name){
		this->name = name;
	}

	void printUsers(){
		set<int>::iterator user_it;
		cout<<"Users: ";
		for(user_it = users.begin(); user_it != users.end(); ++user_it){
			cout<< *user_it<<" ";
		}
		cout<<"\n";

	}
	void printGroups(){
		set<int>::iterator groups_it;
		cout<<"Groups: ";
		for(groups_it = groups.begin(); groups_it != groups.end(); ++groups_it){
			cout<< *groups_it<<" ";
		}
		cout<<"\n";
	}

	void addUser(int id){
		users.insert(id);
	}

	void deleteUser(int id){
		if(users.find(id) != users.end()){
			users.erase(id);
		}
		else{
			cout<<"User id "<<id<<" is not part of series Id "<<this->id<<"\n";
		}
	}

	void addGroup(int id){
		groups.insert(id);
	}
	void deleteGroup(int id){
		if(groups.find(id) != groups.end()){
			groups.insert(id);
		}else{
			cout<<"Users Id "<<id<<" is not part of series Id "<<this->id<<"\n";
		}
	}

	set<int> userSet(){
		return users;
	}

	set<int> groupsSet(){
		return groups;
	}

};

class Group{

private:
	std::string name;
	int id;
	std::set<int>series_list;
	std::set<int>users;

public:
	Group(int id,string name){
		this->id = id;
		this->name = name;
	}

	Group(int id){
		this->id = id;
	}

	Group(){
		this->id = -1;
	}

	void printName(){
		cout<<"GroupName: "<<name<<endl;
	}

	void printSeries(){
		set<int>::iterator series_it;
		cout<<"SeriesId: ";
		for(series_it = series_list.begin(); series_it != series_list.end(); ++series_it){
			cout<<*series_it<<" ";
		}
		cout<<"\n";
	}

	void printUsers(){
		set<int>::iterator user_it;
		cout<<"UserId: ";
		for(user_it = users.begin(); user_it != users.end(); ++user_it){
			cout<<*user_it<<" ";
		}
		cout<<"\n";

	}

	string getName(){
		return name;
	}

	void setName(string name){
		this->name = name;
	}

	void addUser(int id){
		users.insert(id);
	}

	void deleteUser(int id){
		if(users.find(id) != users.end()){
			users.erase(id);
		}
		else{
			cout<<"User Id "<<id<<" is not part of Group Id "<<this->id<<"\n";
		}
	}

	void addSeries(int id){
		series_list.insert(id);
	}
	void deleteSeries(int id){
		if(series_list.find(id) != series_list.end()){
			series_list.erase(id);
		}
		else{
			cout<<"Series Id: "<<id<<" is not part of Group Id "<<this->id<<"\n";
		}

	}

	set<int> userSet(){
		return users;
	}

	set<int> seriesSet(){
		return series_list;
	}

};
 

class Admin{

private:
	Admin(){
		groupId = 0;
		userId = 0;
		seriesId = 0;

	} // Private so that it can  not be called
	Admin(Admin const&){};             // copy constructor is private
	Admin& operator=(Admin const&){};  // assignment operator is private
	static Admin* m_pInstance;
	int groupId;
	int userId ;
	int seriesId;
	map<int, Series>idToSeriesMap;
	map<int, Group>idToGroupMap;
	map<int, User>idToUserMap;

	int nextUserId(){
		return userId++;
	}

	int nextGroupId(){
		return groupId++;
	}

	int nextSeriesId(){
		return seriesId++;
	}

public:
	static Admin* Instance(){
		if (!m_pInstance)   // Only allow one instance of class to be generated.
      		m_pInstance = new Admin;
   		return m_pInstance;
	}

	void modifyUserName(int id, string name){
		idToUserMap[id].setName(name);
	}

	void modifyUserEmail(int id, string new_email){
		idToUserMap[id].setEmail(new_email);
	}

	void modifySeriesName(int id, string new_name){
		idToSeriesMap[id].setName(new_name);
	}

	int modifyGroupName(int id, string name){
		idToGroupMap[id].setName(name);
	}

	int CreateUser(string name, string email){
		int id = nextUserId();
		User new_user(id, name, email);
		idToUserMap.insert(make_pair(id, new_user));
		return id;
	}

	void deleteUser(int id){
		if(idToUserMap.find(id) == idToUserMap.end()){
			cout<<"User id does not exist\n";
			return;
		}
		set<int>groups = idToUserMap[id].groupsSet();
		set<int>::iterator it;
		for(it = groups.begin(); it != groups.end();++it){
			idToGroupMap[*it].deleteUser(id);
		}
		set<int>user_inivited_series =  idToUserMap[id].userInvitedSeriesSet();
		for(it = user_inivited_series.begin(); it != user_inivited_series.end();++it){
			idToSeriesMap[*it].deleteUser(id);
		}

		set<int>group_inivited_series =  idToUserMap[id].groupInvitedSeriesSet();
		for(it = group_inivited_series.begin(); it != group_inivited_series.end();++it){
			idToSeriesMap[*it].deleteUser(id);
		}

		idToUserMap.erase(id);
	}

	int createSeries(string name){
		int id = nextSeriesId();
		Series new_series(id, name);
		idToSeriesMap.insert(make_pair(id, new_series));
		return id;
	}

	void deleteSeries(int id){
		if(idToSeriesMap.find(id) == idToSeriesMap.end()){
			cout<<"Series does not exist\n";
			return;
		}

		set<int>users =	idToSeriesMap[id].userSet();
		set<int>::iterator it;
		set<int>::iterator it2;
		for(it = users.begin();it != users.end(); ++it){
			idToUserMap[*it].deleteInivitesSeries(id);
		}
		set<int>groups = idToSeriesMap[id].groupsSet();
		for(it = groups.begin();it != groups.end();++it){
			idToGroupMap[*it].deleteSeries(id);
			set<int>users2 = idToGroupMap[*it].userSet();
			for(it2 = users2.begin(); it2 != users2.begin(); ++it2){
				idToUserMap[*it2].deleteGroupInivitesSeries(id);
			}
		}
		idToSeriesMap.erase(id);
	}

	int createGroup(string name){
		int id = nextGroupId();
		Group new_group(id,name);
		idToGroupMap.insert(make_pair(id,new_group));
		return id;
	}

	void deleteGroup(int id){
		if(idToGroupMap.find(id) == idToGroupMap.end()){
			cout<<"Groupd id "<<id<<" does not exists\n";
			return ;
		}

		set<int>users = idToGroupMap[id].userSet();
		set<int>::iterator it;
		set<int>::iterator it2;
		for(it = users.begin(); it != users.end(); ++it){
			idToUserMap[*it].deleteGroup(id);
		}

		set<int>series_list = idToGroupMap[id].seriesSet();
		for(it2 = series_list.begin(); it2 != series_list.end(); ++it2){
			idToSeriesMap[*it2].deleteGroup(id);
			for(it = users.begin(); it != users.end(); ++it){
				idToUserMap[*it].deleteGroupInivitesSeries(*it2);
			}
		}

	}

	void linkUserToGroup(int user_id, int group_id){
		if(idToUserMap.find(user_id) == idToUserMap.end()){
			cout<<"User id does not exist\n";
			return ;
		}
		if(idToGroupMap.find(group_id) == idToGroupMap.end()){
			cout<<"Group id does not exist\n";
			return ;
		}
		idToUserMap[user_id].addGroup(group_id);
		idToGroupMap[group_id].addUser(user_id);
		set<int>series = idToGroupMap[group_id].seriesSet();
		set<int>::iterator it;
		for(it = series.begin(); it != series.end();++it){
			idToUserMap[user_id].addGroupInivitesSeries(*it);
			idToSeriesMap[*it].addUser(user_id);
		}

	}

	void UnLinkUserToGroup(int user_id, int group_id){
		if(idToUserMap.find(user_id) == idToUserMap.end()){
			cout <<"User id does not exist\n";
			return ;
		}
		if(idToGroupMap.find(group_id) == idToGroupMap.end()){
			cout<<"Group Id does not exist\n";
			return ;
		}

		idToUserMap[user_id].deleteGroup(group_id);
		idToGroupMap[group_id].deleteUser(user_id);
		set<int>series = idToGroupMap[group_id].seriesSet();
		set<int>::iterator it;
		for(it = series.begin(); it != series.end();++it){
			idToUserMap[user_id].deleteGroupInivitesSeries(*it);
			idToSeriesMap[*it].deleteUser(user_id);
		}
	}

	void invitesUserToSeries(int user_id, int series_id){
		if(idToUserMap.find(user_id) == idToUserMap.end()){
			cout <<"User id does not exist\n";
			return ;
		}

		if(idToSeriesMap.find(series_id) == idToSeriesMap.end()){
			cout <<"Series id does not exist\n";
			return ;
		}

		idToUserMap[user_id].addInivitesSeries(series_id);
		idToSeriesMap[series_id].addUser(user_id);
	} 

	void UnInvitesUserToSeries(int user_id, int series_id){
		if(idToUserMap.find(user_id) == idToUserMap.end()){
			cout <<"User id does not exist\n";
			return ;
		}

		if(idToSeriesMap.find(series_id) == idToSeriesMap.end()){
			cout <<"Series id does not exist\n";
			return ;
		}

		idToUserMap[user_id].deleteInivitesSeries(series_id);
		idToSeriesMap[series_id].deleteUser(user_id);
	}

	void invitesSeriesToGroup(int series_id, int group_id){

		if(idToSeriesMap.find(series_id) == idToSeriesMap.end()){
			cout <<"Series id does not exist\n";
			return ;
		}

		if(idToGroupMap.find(group_id) == idToGroupMap.end()){
			cout<<"Group Id does not exist\n";
			return ;
		}

		set<int> users = idToGroupMap[group_id].userSet();
		idToGroupMap[group_id].addSeries(series_id);
		idToSeriesMap[series_id].addGroup(group_id);
		set<int>::iterator it;
		for(it = users.begin();it != users.end();++it){
			idToUserMap[*it].addGroupInivitesSeries(series_id);
			idToSeriesMap[series_id].addUser(*it);
		}

	}

	void UnIvitesSeriesToGroup(int series_id, int group_id){
		if(idToSeriesMap.find(series_id) == idToSeriesMap.end()){
			cout <<"Series id does not exist\n";
			return ;
		}

		if(idToGroupMap.find(group_id) == idToGroupMap.end()){
			cout<<"Group Id does not exist\n";
			return ;
		}

		set<int> users = idToGroupMap[group_id].userSet();
		idToGroupMap[group_id].deleteSeries(series_id);
		idToSeriesMap[series_id].deleteGroup(group_id);
		set<int>::iterator it;
		for(it = users.begin();it != users.end();++it){
			idToUserMap[*it].deleteGroupInivitesSeries(series_id);
			idToSeriesMap[series_id].deleteUser(*it);
		}
	}

	void printAllUsersInSeries(int series_id){
		if(idToSeriesMap.find(series_id) == idToSeriesMap.end()){
			cout <<"Series id does not exist\n";
			return ;
		}

		idToSeriesMap[series_id].printUsers();
	}

	void printAllInvitedSeriesOfUser(int user_id){
		if(idToUserMap.find(user_id) == idToUserMap.end()){
			cout <<"User id does not exist\n";
			return ;
		}
		idToUserMap[user_id].printSeries();
	}

	void printAllUsersOfGroup(int group_id){
		if(idToGroupMap.find(group_id) == idToGroupMap.end()){
			cout<<"Group Id does not exist\n";
			return ;
		}
		idToGroupMap[group_id].printUsers();

	}

	void printAllGroupsOfUser(int user_id){
		if(idToUserMap.find(user_id) == idToUserMap.end()){
			cout <<"User id does not exist\n";
			return ;
		}
		idToUserMap[user_id].printGroups();

	}

	void printAllGroupsForSeries(int series_id){
		if(idToSeriesMap.find(series_id) == idToSeriesMap.end()){
			cout <<"Series id does not exist\n";
			return ;
		}

		idToSeriesMap[series_id].printGroups();

	}

	void printAllSeriesOfGroup(int group_id){
		if(idToGroupMap.find(group_id) == idToGroupMap.end()){
			cout<<"Group Id does not exist\n";
			return ;
		}
		idToGroupMap[group_id].printSeries();

	}
 };

 Admin* Admin::m_pInstance = NULL; 


 int main(){
 	char c;
 	int number;
 	while(true){
 		cout<<"\nInsert ('q') for Query and ('a') Admin actions\n";
 		c = getchar();
 		switch(c){
 			case 'q':{
 					Admin::Instance()->printAllUsersInSeries(1);
 			}break;

 			case 'a':{
 					cout<<"\npress c->create d-> delete e-> edit \n";
 					c= getchar();
 					switch(c){

 						case 'c':{
 							cout<<"create c-> series u->user g->group\n";
 							
 						}break;

 						case 'd':{

 						}break;
 						case 'e'{

 						}break;
 						default:{}break;
 					}
 				}

 			}break;

 			default: {}break;
 		}

 	}
 	return 0;
 }
