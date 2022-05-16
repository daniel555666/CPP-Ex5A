
#include"OrgChart.hpp"
using namespace std;

namespace ariel{

    OrgChart& OrgChart::add_root(string root){
        if(this->head==NULL){
            Node new_root;
            new_root.data=root;
            this->head=&new_root;
            return *this;
        }
        //need to fill
        return *this;
    }

    OrgChart& OrgChart::add_sub(string bos,string object){
        return *this;
    }
    OrgChart::Iterator OrgChart::begin_level_order(){
        return Iterator(this->head);
    }
    OrgChart::Iterator OrgChart::end_level_order(){
        return Iterator();
    }
    OrgChart::Iterator OrgChart::begin_reverse_order(){
        return Iterator(this->head);
    }
    OrgChart::Iterator OrgChart::reverse_order(){
        return Iterator();        
    }
    OrgChart::Iterator OrgChart::begin_preorder(){
        return Iterator(this->head);
    }
    OrgChart::Iterator OrgChart::end_preorder(){
        return Iterator();
    }
    ostream& operator << (ostream& output, const OrgChart& mat){
        return output;
    }
    OrgChart::Iterator OrgChart::begin(){
        return Iterator(this->head);
    }
    OrgChart::Iterator OrgChart::end(){
        return Iterator();
    }

    OrgChart::Iterator& OrgChart::Iterator::operator++(){
        return *this;
    }

    bool OrgChart::Iterator::operator!=(const Iterator& other)const{
        return false; 
    }
     bool OrgChart::Iterator::operator==(const Iterator& other)const{
        if((this->pitr)==NULL&&(other.pitr)==NULL){
            return true;
        }
        if((this->pitr)==NULL||(other.pitr)==NULL){
            return false;
        }
        return this->pitr==other.pitr; 
    }
    string* OrgChart::Iterator:: operator ->(){
        return &(this->pitr->data);//need to check if null
    }
    string OrgChart::Iterator::operator *(){
        // if(||*this==NULL||this->pitr==NULL||){
        //     return NULL;
        // }
        // return this->pitr->data;
        return "hey";
    }


}
