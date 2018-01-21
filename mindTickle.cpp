#include<iostream>
#include<set>
#include<map>
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
		this.id = id;
		this.name = name;
		this.email = email;
	}

	User(int id){
		this.id = id;

	}

	void printSeries(){
		 set<int>::iterator user_inivited_series_it; 

		 cout <<"SeriesId: ";
		 for (user_inivited_series_it = user_inivited_series.begin();; user_inivited_series_it!=user_inivited_series.end();  ++user_inivited_series_it){
        	cout <<*user_inivited_series_it << " ";
        }

        set<int>::iterator group_inivited_series_it;

		 for (group_inivited_series_it = group_inivited_series.begin();; group_inivited_series_it!=group_inivited_series.end();  ++group_inivited_series_it){
		 	user_inivited_series_it = user_inivited_series.find(*group_inivited_series_it);
		 	 _
		 	if(user_inivited_series_it == user_inivited_series.end())
        	cout <<*group_inivited_series_it << " ";
        }

        cout<<"\n";

	}

	void printGroups(){

		set<int>::iterator groups_it; 

		cout<<"UserId: "
		 for (groups_it = groups.begin();; groups_it!=groups.end();  ++groups_it){
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
		this.name = name;
	}

	void setEmail(string email){
		this.email = email;
	}

	void AddInivitesSeries(int id){
		user_inivited_series.insert(id);

	}

	void AddGroupInivitesSeries(int id){
		group_inivited_series.insert(id);
	}

	void AddGroup(int id){
		groups.insert(id);
	}

	void DeleteInivitesSeries(int id){
		user_inivited_series.erase(id);
	}

	void DeleteGroupInivitesSeries(int id){
		group_inivited_series.erase(id);
	}

	void DeleteGroup(int id){
		groups.erase(id);
	}

	set<int> groupSet(){
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
		this.id = id;
		this.name = name;
	}

	Series(int id){
		this.id = id;
	}

	void printName(){
		cout<<"UserName: "<<name<<"\n";
	} 

	string getName(){
		return name;
	}

	void setName(){
		this.name = name;
	}

	void printUsers(){
		set<int>::iterator user_it;
		cout<<"Users: "
		for(user_it = users.begin();user_it != users.end();++user_it){
			cout<< *user_it<<" ";
		}
		cout<<"\n";

	}
	void printGroups(){
		set<int>::iterator groups_it;
		cout<<"Groups: "
		for(groups_it = groups.begin();groups_it != groups.end();++groups_it){
			cout<< *groups_it<<" ";
		}
		cout<<"\n";
	}

	void addUser(int id){
		users.insert(id);
	}

	void deleteUser(int id){
		users.erase(id);
	}

	void addGroup(int id){
		groups.insert(id);
	}
	void deleteGroup(){
		groups.insert(id);
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
		this.id = id;
		this.name = name;
	}

	Group(int id){
		this.id = id;
	}

	void printName(){
		cout<<"GroupName: "<<name<<endl;
	}

	void printSeriesList(){
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
		this.name = name;
	}

	void addUser(int id){
		users.insert(id);
	}

	void deleteUser(int id){
		users.erase(id);
	}

	void addSeries(int id){
		series_list.insert(id);
	}
	void deleteSeries(int id){
		series_list.erase(id);

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
	Admin(){};  // Private so that it can  not be called
	Admin(Admin const&){};             // copy constructor is private
	Admin& operator=(Admin const&){};  // assignment operator is private
	static Admin* m_pInstance;
	int groupId = 0;
	int userId = 0;
	int seriesId = 0;
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

	int CreateUser(string name, string email){
		int id = nextUserId();
		User new_user(id, name, email);
		idToUserMap.insert(make_pair(id, new_user));
		return id;
	}

	void deleteUser(int id){
		//delete idToUserMap[id];
		//idToUserMap.erase(id);
	}

	void modifyUserName(int id, name){
		idToUserMap[id].setName(name);
	}

	void modifyUserEmail(int id, string new_email){
		idToUserMap[id].setEmail(new_email);
	}

	void linkUserToGroup(int user_id, int group_id){
		idToUserMap[user_id].AddGroup(group_id);
		idToGroupMap[group_id].addUser(user_id);
		set<int>series = idToGroupMap[group_id].seriesSet();
		set<int>::iterator it;
		for(it = series.begin(); it != series.end();++it){
			idToUserMap[user_id].AddGroupInivitesSeries(*it);
			idToSeriesMap[*it].addUser(user_id);
		}

	}

	void UnLinkUserToGroup(int user_id, int group_id){
		//idToUserMap[user_id].DeleteGroup(group_id);
	}

	void invitesUserToSeries(int user_id, int series_id){
		idToUserMap[user_id].AddInivitesSeries(series_id);
		idToSeriesMap[series_id].addUser(user_id);
	} 

	void UnInvitesUserToSeries(int user_id, int series_id){
		//idToUserMap[user_id].DeleteInivitesSeries(series_id);
	} 

	int createSeries(string name){
		int id = nextSeriesId();
		Series new_series(id, name);
		idToSeriesMap.insert(make_pair(id, new_series));
		return id;
	}

	void deleteSeries(int id){


	}

	void modifySeriesName(int id, string new_name){
		idToSeriesMap[id].setName(new_name);
	}

	int createGroup(string name){
		int id = nextGroupId();
		Group new_group(id,name);
		idToGroupMap.insert(make_pair(id,new_group));
		return id;
	}

	void deleteGroup(){

	}

	int modifyGroupName(int id, string name){
		idToGroupMap[id].setName(name);
	}

	void invitesSeriesToGroup(int series_id, int group_id){
		set<int> users = idToGroupMap[group_id].userSet();
		idToGroupMap[group_id].addSeries(series_id);
		idToSeriesMap[series_id].addGroup(group_id);
		set<int>::iterator it;
		for(it = users.begin();it != users.end();++it){
			idToUserMap[*id].AddGroupInivitesSeries(series_id);
			idToSeriesMap[series_id].addUser(*it);
		}

	}

	void UnIvitesSeriesToGroup(int series_id, int group_id){

	}


 };

 int main(){

 	return 0
 }
