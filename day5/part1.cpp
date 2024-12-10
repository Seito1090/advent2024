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
        Page* getPage(int page){
            for (Page& p : pages){ // Iterate by reference
                if (p.number == page) return &p; // Address of the object in the vector
            }
            return NULL;
        }
        bool hasPage(int nbr){
            for (Page p : pages){
                if (p.number == nbr) return true;
            }
            return false;
        }
        void putPage(Page page){ pages.push_back(page);}
};

PageList getinput(vector<string>* ptr_input){
    vector<string> orderingPart;
    string line;
    regex str_expr(R"((\d{2})|(\d{2}))");
    bool split = false;
    while (getline(cin,line)){
        regex_iterator<string::iterator> rit(line.begin(), line.end(), str_expr);
        regex_iterator<string::iterator> rend;
        if (rit==rend){
            split = true;
        }
        if (split && line != "") (*ptr_input).push_back(line);
        else if (line != "") orderingPart.push_back(line);
    }
    //Creating pages
    PageList pages;
    for (string page : orderingPart){
        int a = page.find("|");
        int nb_1 = stoi(page.substr(0,a));
        page.erase(0,a+1);
        int nb_2 = stoi(page);
        //Check if page already there
        Page* ptr_page;
        if ((ptr_page = pages.getPage(nb_1)) == NULL){
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
    
    return pages;
}

vector<int> my_split(string line , string delimiter){
    vector<int> values;
    if (line == "") return values;
    int pos = 0;
    while ((pos = line.find(delimiter)) != EOF){
        values.push_back(stoi(line.substr(0, pos)));
        line.erase(0, pos+delimiter.size());
    }
    values.push_back(stoi(line));
    return values;
}

void check_input(vector<string>* ptr_input, PageList* ptr_pages){
    int linePos = 0;
    string line;
    int init_size = (*ptr_input).size();
    for (int _ = 0; _ < init_size; _++){
        line = (*ptr_input).at(linePos);
        //split line into ints 
        vector<int> values = my_split(line, ",");
        if (values.size() == 0) {
            cout<<"CYA"<<endl;
            return;
        }
        //check each position 
        bool lineDel = false;
        for (int a = 0; a < values.size(); a++){
            if ((*ptr_pages).hasPage((values.at(a)))){
                Page* to_check = (*ptr_pages).getPage((values.at(a)));
                for (int b = a; b >= 0; b--){
                    auto occ = find((*to_check).numbersAfter.begin(), (*to_check).numbersAfter.end(), values.at(b));
                    if (occ != (*to_check).numbersAfter.end()) {
                        lineDel = true;
                        break;
                    }
                }
            }
        }
        //delete the line if needed
        if (lineDel) {(*ptr_input).erase((*ptr_input).begin()+linePos);}
        else linePos++;
    }
}

int calcValue(vector<string>* ptr_input){
    int value = 0;
    for (string line : *ptr_input){
        vector<int> lineInt = my_split(line, ",");
        int sz = lineInt.size();
        value+=lineInt.at(sz/2);
    }
    return value;
}

int main(){
    vector<string> input;
    vector<string>* ptr_input = &input;
    PageList pages = getinput(ptr_input);
    PageList* ptr_pages = &pages;
    check_input(ptr_input, ptr_pages);
    cout<<calcValue(ptr_input)<<endl;
    return 0;
}
