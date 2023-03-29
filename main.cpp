#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

int IndexOfMinimumElement(const std::vector<double>& input) 
{
    if (input.empty()) 
        return -1;
    auto ptrMinElement = std::min_element(input.begin(), input.end());
    return std::distance(input.begin(), ptrMinElement);
}


using namespace std;

// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
vector<string> split1 (string s, string start, string end){
  size_t pos = 0, start_len = start.length(), end_len = end.length();
  std:: string token;
  vector<string> res;
  while ((pos = s.find(start)) != std::string::npos){
    if (s.substr(pos - 1, 1) == "\""){
      s.erase(0, pos +start.length());
      continue;
    }
    s.erase(0, pos +start.length());
    pos = s.find(end);
    token = s.substr(0, pos);
    s.erase(0, pos + end.length());
    res.push_back(token); 
}
return res; 
}

int main() {
    size_t pos = 0;
    int id;
    int vol;
    int part;
    int t;
    string st;
    std::ifstream inFile;
    inFile.open("avito1.txt");
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    std::ifstream inFile1;
    inFile1.open("apart.txt");
    std::stringstream strStream1;
    strStream1 << inFile1.rdbuf();
    std::string str1 = strStream1.str();
    string s1 = ",\"name\":\"";
    string e1 = "\"";
    string s2 = ",\"id\":";
    string e2 = ",";
    string s4 = "\"salePriceU\":";
    string e4 = ",\"averagePrice\":";
    vector<string> vv = split1(str, s4, e4);
    vector<string> v1 = split1(str, s1, e1);
    //for (auto i : v1) cout << i << endl;
    vector<string> v2 = split1(str, s2, e2);
    //for (auto i : v2) cout << i << endl;
    vector<string> v5 = split1(str, s4, e4);
    //for (auto i : v5) cout << i << endl;
  for(int i = 0; i < v1.size(); i++){
    if ((pos = v1[i].find("Max")) != std::string::npos){
      continue;
    }
    if ((pos = v1[i].find("Макс")) != std::string::npos){
      continue;
    }
    if ((pos = v1[i].find("макс")) != std::string::npos){
      continue;
    }
    cout << v1[i] << endl;
    cout << v2[i] << endl;
    cout << v5[i] << endl;
  }
  for(int i = 0; i < v1.size(); i++){
    id = stoi(v2[i]);
    vol = id / 100000;
    part = id / 1000;
    if (vol>=0&&vol<=143){
      t = 1;
      st = "01";
    }
    if (vol>=144&&vol<=287){
      t = 2;
      st = "02";
    }
    if (vol>=1602&&vol<=1724){
      t = 11;
      st = "11";
    }
    if (vol>=288&&vol<=431){
      t = 3;
      st = "03";
    }
    if (vol>=432&&vol<=719){
      t = 4;
      st = "04";
    }
    if (vol>=720&&vol<=1007){
      t = 5;
      st = "05";
    }
    if (vol>=1008&&vol<=1061){
      t = 6;
      st = "06";
    }
    if (vol>=1062&&vol<=1115){
      t = 7;
      st = "07";
    }
    if (vol>=1116&&vol<=1169){
      t = 8;
      st = "08";
    }
    if (vol>=1170&&vol<=1313){
      t = 9;
      st = "09";
    }
    if (vol>=1314&&vol<=1601){
      t = 10;
      st = "10";
    }
    cout << "<div class=\"col-md-4\"><a href=\"https://www.wildberries.ru/catalog/" + v2[i] + "/detail.aspx\" target=\"_blank\"><img height=\"250\" src=\"https://basket-" + st + ".wb.ru/vol" + to_string(vol) + "/part" + to_string(part) + "/" + to_string(id) + "/images/c516x688/1.jpg\"><img height=\"250\" src=\"https://basket-" + st + ".wb.ru/vol" + to_string(vol) + "/part" + to_string(part) + "/" + to_string(id) + "/images/c516x688/2.jpg\"><img height=\"250\" src=\"https://basket-" + st + ".wb.ru/vol" + to_string(vol) + "/part" + to_string(part) + "/" + to_string(id) + "/images/c516x688/3.jpg" + "\"><h1 class=\"salePrices\"><span class=\"badge badge-dark\">" + v5[i] + "</span></h1></a></div>" << endl;
  }
   // cout << v1[0] ;
    /*string s3 = ", ";
    string e3 = " ";
    vector<string> v3;
    vector<double> vint;
    for(int i = 0; i < v1.size(); i++){
       v3 = split1(v1[i], s3, e3);
      cout << v3[0] << endl;
      cout << v2[i] << endl;
      int a;
      int b;
      std::istringstream ( v3[0] ) >> a;
      std::istringstream ( v2[i] ) >> b;
      vint.push_back(b / a);
      }
    for (auto i : vint) cout << i << endl;
    cout << "ddd" << endl;
    cout << IndexOfMinimumElement(vint) << std::endl;
    cout << "https://www.avito.ru/dolgoprudnyy/kvartiry/" + vv[IndexOfMinimumElement(vint)] << std::endl;*/
    return 0;
}