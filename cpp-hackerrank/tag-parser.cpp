#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <memory>
#include <fstream>
#define MISSING_RESULT_VAL "Not Found!"

using namespace std;

// forward declaration;
class Tag;

class Tag 
{
    public: 
        Tag(string n, shared_ptr<Tag> p) : name(n), parent(p) {};
        Tag() = default;
        Tag& operator=(shared_ptr<Tag> tg) {
            if (this != tg.get()) {
                name = tg->name;
                parent = tg->parent;
                children = tg->children;
                attributes = tg->attributes;
            }
            return *this;
        }
        void addChild(shared_ptr<Tag> tag) {
            children.emplace_back(tag);
        };
        bool empty() {
            return name.size() == 0;
        }
        void attr(string key, string val) {
            attributes.emplace_back(key, val);
        }
        string attr(string attr_name) {
            for (auto val : attributes) {
                if (val.first == attr_name) {
                    return val.second;
                }
            }
            return "";
        }
        
        vector<shared_ptr<Tag>> children{};
        vector<pair<string, string>> attributes{};
        string name;
        shared_ptr<Tag> parent;
};



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // TODO: when submitting, replace file with cin
   ofstream file;
   file.open("in1");

    int N, Q;
    file >> N >> Q;
    // get the N lines
    string line;
    
    bool in_tag_name = false, 
        in_tag_body = false,
        in_closing_tag = false,
        in_attribute_name = false,
        in_attribute_value = false;

    string tag_name = "", attribute_name = "", attribute_value = "";
    shared_ptr<Tag> current = nullptr, parent = nullptr;

    for (int i = 0; i < N; i++) {
        getline(file, line); 

        for (char& c: line) {
            if (c == '<') {
                in_tag_name = true;
                // start new tag
                parent = current;
                current = nullptr;
            } else if (in_tag_name) {
                if (c == '/') {
                    in_closing_tag = true;
                } else if (c == '>') {
                    in_tag_name = false;
                    in_tag_body = true;
                } else if (tag_name.size()) {
                    if (c == ' ') {
                        in_tag_name = false;
                        current = make_shared<Tag>(tag_name, parent);
     
                        tag_name = "";
                        in_attribute_name = true;
                        // initialize new tag
                    } else tag_name += c;
                } else {
                    if (c != ' ') {
                        in_tag_name = true;
                        tag_name += c;
                    }
                }
            } else if (in_closing_tag) {
                if (c == '>') {
                    in_closing_tag = false;
                    in_tag_body = false;
                }
            } else if (in_attribute_name) {
                if (attribute_name.size()) {
                    if (c == ' ') {
                        in_attribute_name = false;
                        in_attribute_value = true;
                    } else {
                        attribute_name += c;
                    }
                } else if (c != ' ') {
                    attribute_name += c;
                } else if (c == '>') {
                    in_tag_body = true;
                    in_attribute_name = false;
                }
            } else if (in_attribute_value) {
                if (c == '>') {
                    in_attribute_name = false;
                    in_attribute_name = false;
                    in_tag_body = true;
                    // add attribute to tag
                    current->attr(attribute_name, attribute_value);
                    attribute_name = "";
                    attribute_value = "";
                } else if (attribute_value.size()) {
                    if (c == ' ') {
                        in_attribute_value = false;
                        in_attribute_name = true;
                        // add attribute to tag
                        current->attr(attribute_name, attribute_value);
                        attribute_name = "";
                        attribute_value = "";
                    } else {
                        attribute_value += c;
                    }
                } else {
                    if (c != ' ') attribute_value += c;
                }
            } else if (in_tag_body) {
                if (c == '<') {
                    in_tag_name = true;
                }
            }
        }  
    }

    // get to the root
    while (current->parent) {
        current = current->parent;
    }

    // process queries
    bool on_tag_name = true, on_attribute_val = false;
    string query_result = MISSING_RESULT_VAL;
    shared_ptr<Tag> tag = nullptr;
    for (int i = 0; i < Q; i++) {
        getline(file, line); 
        cout << line << endl;
      //   tag = nullptr;
      //   for (char& c: line) {
      //       if (on_tag_name) {
      //           if (c == '.') {
      //               // look for tag in 
      //               bool tag_changed = false;
      //               if (tag) {
      //                   for (auto const& child: tag->children) {
      //                       if (child->name == tag_name) {
      //                           tag = child;
      //                           tag_changed = true;
      //                           tag_name = "";
      //                           break;
      //                       }
      //                   }
      //                   if (!tag_changed) goto after_line_query;
      //               } else {
      //                   if (current->name == tag_name) {
      //                       tag = current;
      //                       tag_name = "";
      //                   } else goto after_line_query;
      //               }
      //           } else if (c == '~') {
      //               on_tag_name = false;
      //               on_attribute_val = true;
      //           }
      //       } else if (on_attribute_val) {
      //           if (c != ' ') attribute_name += c;
      //       }
      //   }

      //   if (on_attribute_val) {
      //       if (tag->attr(attribute_name).size() > 0) {
      //           query_result = tag->attr(attribute_name);
      //       }
      //   }

      //   after_line_query:
      //       cout << query_result << endl;
      //       query_result = MISSING_RESULT_VAL;
      //       on_tag_name = true;
      //       on_attribute_val = false;
    }

    return 0;
}
