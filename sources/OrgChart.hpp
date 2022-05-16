#include <iostream>
#include <string>
#include<vector>
using namespace std;

namespace ariel
{

    class OrgChart
    {

        typedef struct Node
        {
            string data;
            vector<struct Node> *Lower_Lvl_Arr;
        } Node;

    public:
        Node *head;
        // OrgChart(Node* new_head);
        OrgChart& add_root(string root);
        OrgChart& add_sub(string bos, string object);

            class Iterator
        {

        private:
            Node *pitr;

        public:
            Iterator(Node *p_itr) : pitr(p_itr) {}
            Iterator(){
                this->pitr=NULL;
            }


            Iterator& operator++();
            bool operator!=(const Iterator& other)const;
            bool operator==(const Iterator& other)const;
            string* operator ->();
            string operator *();

        };

        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

        friend ostream& operator<<(ostream &output, const OrgChart &mat);
        Iterator begin();
        Iterator end();
    };

}