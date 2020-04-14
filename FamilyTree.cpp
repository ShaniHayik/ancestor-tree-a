//
// Created by shani and yarden on 05/04/2020.
//

#include "FamilyTree.hpp"
#include <string>
#include <exception>
#include <stdexcept>
#include <iomanip>

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
    string gender = "";
    int count = 1;
    string answer = "";
    int i = 2;

    if (this->root->getName() == name) {
        return "me";
    }

    if (this->root->getFather()->getName() == name) {
        return "father";
    } else if (this->root->getMother()->getName() == name) {
        return "mother";
    } else {
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

        Node *son = ans->getSon();

         if(son->getFather() == nullptr)
                gender = "mother";

         else if(son->getFather()->getName() == name)
             gender = "father";

         else gender = " ";

        if(son->getMother() == nullptr)
            gender = "father";

        else if ((son->getMother()->getName() == name))
                gender = "mother";

        else gender = " ";


            while (i < count) {
                answer += "great-";
                i++;
            }
            answer += "grand";
            answer+= gender;
        }
        return answer;
    }



const string& Tree::find(const string& related) {
    int i=0, count=2; int flag=0;

    if (related == "me")
        return this->root->getName();

    if(related == "mother")
        return this->root->getMother()->getName();

    else if(related == "father")
        return this->root->getFather()->getName();

    else if (related.length()<11)
        throw std::out_of_range{ "The tree cannot handle the " + related + " relation"};

    else {
        i=0;
        while(i<related.length()-11) {
            string subs = related.substr(i, 6);
            if(related.substr(i, 6) == "great-") {
                count++;
            }
            else {
                flag = 1;
            }
            i+=6;
        }

        if (((related.substr(i, 11) != "grandmother") && (related.substr(i, 11) != "grandfather")) || flag) {
                throw std::out_of_range{ "The tree cannot handle the " + related + " relation"};
        }

        i=2;
        Node* tryFather = this->root->getFather();
        Node* tryMother = this->root->getMother();
        while(i<count) {

            if (tryMother->getMother() != nullptr)
                tryMother = tryMother->getMother();

            if(tryFather->getFather())
                tryFather = tryFather->getFather();

           i++;
        }

        if(relation(tryMother->getName()) == related) {
            return tryMother->getName();
        }

        else return tryFather->getName();
    }
}


//display credit: StackOverFlow site, https://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way

void Tree::display()
{
    if (root == NULL)
    {
        return;
    }

    cout << root->getName() << endl;
    printSubtree(root, "");
    cout << endl;
}



void Tree::printSubtree(Node* root, const string& prefix)
{
    if (root == NULL)
    {
        return;
    }

    bool hasLeft = (root->getMother() != NULL);
    bool hasRight = (root->getFather() != NULL);

    if (!hasLeft && !hasRight)
    {
        return;
    }

    cout << prefix;
    cout << ((hasLeft  && hasRight) ? "├── " : "");
    cout << ((!hasLeft && hasRight) ? "└── " : "");

    if (hasRight)
    {
        bool printStrand = (hasLeft && hasRight && (root->getFather()->getFather() != NULL || root->getFather()->getMother() != NULL));
        string newPrefix = prefix + (printStrand ? "│   " : "    ");
        cout << root->getFather()->getName() << endl;
        printSubtree(root->getFather(), newPrefix);
    }

    if (hasLeft)
    {
        cout << (hasRight ? prefix : "") << "└── " << root->getMother()->getName() << endl;
        printSubtree(root->getMother(), prefix + "    ");
    }
}


void Tree::remove(const string& name) {
    Node* ans = findTheSon(name, this->root);
    if(ans == nullptr) {
        throw std::out_of_range{ "The name does not exist, there is no node to delete"};
    }

    else {
        Node* son = ans->getSon();
        if(son->getFather()->getName() == name)
            son->setFather(nullptr);

        else
            son->setMother(nullptr);
    }
}

