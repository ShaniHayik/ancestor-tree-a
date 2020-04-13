//
// Created by shani and yarden on 05/04/2020.
//

#include "FamilyTree.hpp"
using namespace family;

// node implementations
Node::Node(const string& name) : name(name), mother(nullptr), father(nullptr), son(nullptr)
{

}

// tree implementations
Tree::Tree(const string& myName) : root(new Node(myName))
{

}

Tree& Tree::addFather(const string& son, const string& father) {
    addParent(father, son, true);
    return *this;
}

Tree& Tree::addMother(const string& son, const string& mother) {
    addParent(mother, son, false);
    return *this;
}

void Tree::addParent(const string& parent, const string& son, bool addToFather)
{
    Node *ans = findTheSon(son, root);

    if (ans == nullptr) // son doesn't exist in tree
    {
        // cout << "the son is not exist";
        return;
    }

    if(addToFather && ans->getFather() != nullptr) // father already exists in tree
    {
        return;
    }
    if(!addToFather && ans->getMother() != nullptr) // mother already exists in tree
    {
        return;
    }

    Node* parentNode = new Node(parent);
    parentNode->setSon(ans);

    if (addToFather)
        ans->setFather(parentNode);
    else
        ans->setMother(parentNode);
}



Node* Tree::findTheSon(const string& son, Node* check) const {
  if(check == nullptr) return nullptr;
  else if (check->getName() == son) return check;
  else
  {
      Node* tryFather = findTheSon(son, check->getFather());

      if(tryFather != nullptr)
      {
          return tryFather;
      }
      else{
          return findTheSon(son, check->getMother());
      }
  }
}


const string Tree::relation(const string& name) {
    string gender="";
    int count = 1;
    string answer="";
    int i=2;

    if (this->root->getName() == name) {
        return "me";
    }

    if (this->root->getFather()->getName() == name) {
        return "father";
    } else if (this->root->getMother()->getName() == name) {
        return "mother";
    }

    else {
        Node *ans = findTheSon(name, this->root);
        Node *temp;
        temp = ans;

        if (ans == nullptr) {
            return "unrealated";
        }

        while (temp->getSon()->getName() != root->getName()) {
            count++;
            temp = temp->getSon();
        }

        Node* son = ans->getSon();
        if(son->getMother()->getName() == name)
            gender = "mother";

        else if (son->getFather()->getName() == name)
            gender = "father";

        while(i<count) {
            answer+= "great-";
        }
        answer="grand"+gender;
    }
    return answer;
}



//string Node::find(string relation, Node* name) {
////    if (root == NULL || root->name == relation) return root;
////    if (root->mother->name != relation) return relation(name->mother, root);
////    return relation(name->father, root);
//}




