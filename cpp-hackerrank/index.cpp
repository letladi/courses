#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <fstream>
#include <stack>
#include <sstream>
#define MISSING_RESULT_VAL "Not Found!"
using namespace std;

class Tag
{
   public:
      Tag() = default;
      Tag(string n) : name(n) {}
      Tag(Tag&) = default;
      Tag(Tag&&) = default;
      virtual ~Tag() = default;
      Tag& operator=(Tag& tg) {
         if (&tg != this) {
            name = tg.name;
            this->attrs = tg.attrs;
            this->children = tg.children;
         }
         return *this;
      }
      Tag& operator=(Tag&& tg)
      {
         if (&tg != this) {
            name = tg.name;
            this->attrs.swap(tg.attrs);
            this->children.swap(tg.children);
         }
         return *this;
      }

      friend ostream& operator<<(ostream& os, const Tag& tg);

      string name;
      vector<vector<string>> attrs{};
      vector<string> children;
};

ostream& operator<<(ostream& os, const Tag& tg)
{
   os << "tag: " << tg.name << "; ";
   if (tg.attrs.size()) {
      os << "[ ";
      for (const vector<string>& attribute: tg.attrs) {
         os << attribute.front() << "=" << attribute.back() << " ";
      }
      os << "]" << endl;
   }
   
   if (tg.children.size()) {
      os << "[children: ";
      for (const string& childName : tg.children) {
         os << childName << " ";
      }
      os << "]" << endl;
   }
   return os;
}

class Parser
{
   public:
   virtual size_t readLine() = 0;
   string line() { return mLine; }
   void parse();
   void processQuery();
   void clearLine() { mLine.clear(); }
   size_t tag_count() { return tags.size(); }
   friend ostream& operator<<(ostream& os, const Parser& ps);

   protected: 
      string mLine;
      vector<string> roots{};
      vector<Tag> tags{};
};

void Parser::processQuery()
{
   string tag_name{}, attr_name{};
   bool tag_found = true, in_tag_name = true;
   Tag* current = nullptr;
   int c_count = 0, tag_count = 0;
   for (string::iterator it = mLine.begin(), strEnd = mLine.end(); it != strEnd; it++) {
      if (++c_count >= 200) break;

      char c = *it;
      if (c == '\n') {
         c_count = 0;
         continue;
      }
      if (c == '.' || c == '~') {

         // we must first ensure the first tag name is the same as the root tag
         if (tag_count == 0) {
            auto in_root = find(roots.begin(), roots.end(), tag_name);
            if (in_root == roots.end()) {
               tag_found = false;
               break;
            }
         }

         tag_count++;
         
         if (current) {
            auto child_name = find_if(current->children.begin(), current->children.end(), [&tag_name](auto& name) {
               return name == tag_name;
            });

            if (child_name == current->children.end()) {
               tag_found = false;
               break;
            } else {
               auto child = find_if(tags.begin(), tags.end(), [child_name](auto& tg) {
                  return tg.name == *child_name;
               });

               // this maybe redundant
               if (child == tags.end()) {
                  tag_found = false;
                  break;
               } else {
                  current = &(*child);
               }
            }
         } else {
             auto item = find_if(tags.begin(), tags.end(), [&tag_name](Tag& tg) { 
               return tg.name == tag_name; 
            });
            if (item == tags.end()) {
               tag_found = false;
               break;
            } else {
               current = &(*item);
            }
         }
         // after everything reset the name to receive the next tag name
         tag_name.clear();
         in_tag_name = c != '~';

      } else { 
         if (in_tag_name) {
            tag_name += c;
         } else {
            attr_name += c;
         }
      }
   }

   if (tag_found) {
      auto attribute = find_if(current->attrs.begin(), current->attrs.end(), [&attr_name](auto& attr) {
         return attr.front() == attr_name;
      });

      if (attribute == current->attrs.end()) {
         cout << MISSING_RESULT_VAL << endl;
      } else {
         cout << attribute->back() << endl;
      }
   } else {
      cout << MISSING_RESULT_VAL << endl;
   }

   mLine.clear();
}

ostream& operator<<(ostream& os, const Parser& ps)
{
   for (const Tag& tg : ps.tags) {
      os << tg;
   }
   return os;
}

void Parser::parse()
{
   bool in_opening_tag = false,
      in_closing_tag = false,
      in_tag_name = false,
      in_attribute_name = false,
      in_attribute_val = false;

   string tag_name = "", attribute_name = "", attribute_val = "";
   Tag tag;
   vector<vector<string>> tag_attrs{};
   stack<string> tag_stack;
   int c_count = 0;
   for (string::iterator it = mLine.begin(), strEnd = mLine.end(); it != strEnd; it++) {
      if (++c_count >= 200) break;
      
      char c = *it;
      if (c == '\n') {
         c_count = 0;
         continue;
      }
      // on the opening tag (we read the name of the tag and the attributes and their values)
      if (c == '<') {
         in_opening_tag = true;
         in_tag_name = true;
      } else if (in_opening_tag) {
         if (c == '>') {
            in_opening_tag = false;
            in_tag_name = false;
            in_attribute_name = false;
            in_attribute_val = false;
            // create tag and add it to the list of tags
            Tag tg{tag_name};
            // if there is one last attribute, add it to the list of 
            // attributes before continuing
            if (!attribute_val.empty()) {
               tag_attrs.emplace_back(vector<string>{attribute_name, attribute_val});
            }
            tg.attrs.swap(tag_attrs);
            tag_attrs.clear();
            tag_name = attribute_name = attribute_val = "";

            tag_stack.push(tg.name);
            tags.push_back(move(tg));
         } else if (c == '/') {
            in_closing_tag = true;
            in_opening_tag = false;
            in_tag_name = false;

         } else if (in_tag_name) {
            if (tag_name.empty()) {
               if (c != ' ') tag_name += c;
            } else {
               if (c != ' ') {
                  tag_name += c;
               } else {
                  in_tag_name = false;
                  in_attribute_name = true;
               }
            }
            
         } else if (in_attribute_name) {
            if (attribute_name.empty()) {
               if (c != ' ') attribute_name += c;
            } else {
               if (c != ' ') {
                  attribute_name += c;
               } else {
                  in_attribute_name = false;
                  in_attribute_val = true;
               }
            }

         } else if (in_attribute_val) {
            if (attribute_val.empty()) {
               if (c != ' ' && c != '=' && c != '"') attribute_val += c;
            } else {
               if (c != ' ' && c != '"') {
                  attribute_val += c;
               } else {
                  in_attribute_val = false;
                  in_attribute_name = true;
                  tag_attrs.emplace_back(vector<string>{attribute_name, attribute_val});
                  attribute_name = attribute_val = "";
               }
            }
         }
 
      } else if (in_closing_tag) {
         if (c == '>') {
            in_closing_tag = false;
            string child = tag_stack.top();
            tag_stack.pop();
            
            if (tag_stack.size() > 0) {
               string parent = tag_stack.top();
               for (Tag& tag : tags) {
                  if (tag.name == parent) {
                     tag.children.push_back(child);
                  }
               }
            } else {
               // This is a root tag
               roots.push_back(child);
               in_opening_tag = false;
               in_closing_tag = false;
               in_tag_name = false;
               in_attribute_name = false;
               in_attribute_val = false;
            }
            tag_name.clear();
            attribute_name.clear();
            attribute_val.clear();
         }
      }
   }
   // we don't need this anymore
   mLine.clear();
}

class FileParser : public Parser 
{
   public:
      // FileParser(string name) : file(ifstream(name)) {}
      FileParser(ifstream& f) : file(f) {}

      size_t readLine() 
      {
         string str = "";
         getline(file, str);
         mLine += str;
         mLine += '\n';
         return str.size();
      }

   private:
      ifstream& file;
};

class StreamParser : public Parser 
{
   public:
      StreamParser() = default;
      size_t readLine() 
      {
         string str = "";
         getline(cin, str);
         mLine += str;
         mLine += '\n';
         return str.size();
      }
};

int main(void)
{
   string line;
   ifstream file("in1");
   int N, Q;

   if (file.is_open()) {
      getline(file, line);
      stringstream ss(line);
      ss >> N >> Q;
      FileParser parser(file);
      int n = 0;
      while (n < N) {
         parser.readLine();
         n++;
      }

      parser.parse();

      // show queries
      n = 0;
      while (n < Q) {
         parser.readLine();
         parser.processQuery();
         n++;
      }
   }
}