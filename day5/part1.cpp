#include <bits/stdc++.h>
using namespace std;

class Page{
    public:
        int number;
        vector<int> numbersAfter; //numbers that have to be after the one we storing
};

class PageList{
    private:
        vector<Page> pages;
    public:
        Page* hasPage(int page){
            for (Page p : pages){
                if (p.number == page) return &p;
            }
            return NULL;
        }
        void putPage(Page page){ pages.push_back(page);}
};

void getinput(vector<Page>* ptr_pages){
    vector<string> orderingPart;
    vector<string> inputPart;
    string line;
    regex str_expr(R"((\d{2})|(\d{2}))");
    bool split = false;
    while (getline(cin,line)){
        regex_iterator<string::iterator> rit(line.begin(), line.end(), str_expr);
        regex_iterator<string::iterator> rend;
        if (rit==rend){
            split = true;
        }
        cout<<split<<endl;
        if (split && line != "") inputPart.push_back(line);
        else if (line != "") orderingPart.push_back(line);
    }
    cout<<"yahoo"<<endl;
    //Creating pages
    PageList pages;
    for (string page : orderingPart){
        int a = page.find("|");
        int nb_1 = stoi(page.substr(0,a));
        page.erase(0,a+1);
        cout<<page<<endl;
        int nb_2 = stoi(page);
        //Check if page already there
        Page* ptr_page;
        if ((ptr_page = pages.hasPage(nb_1)) == NULL){
            Page newPage;
            newPage.number = nb_1;
            newPage.numbersAfter.push_back(nb_2);
            pages.putPage(newPage);
        } else {
            auto check = count((*ptr_page).numbersAfter.begin(), (*ptr_page).numbersAfter.end(), nb_2);
            if (check == 0){
                (*ptr_page).numbersAfter.push_back(nb_2);
            }
        }
    }
    cout<<"ordering part treated"<<endl;
}

int main(){
    vector<Page> pages;
    vector<Page>* ptr_pages = &pages;
    getinput(ptr_pages);
    return 0;
}
