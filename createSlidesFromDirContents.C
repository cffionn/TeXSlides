#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int createSlidesFromDirContents(const std::string inFileName)
{
  std::ifstream file;
  std::string str; 

  std::vector<std::string>* inStr_p = new std::vector<std::string>;

  
  if(inFileName.find(".txt") != std::string::npos){
    file.open(inFileName.c_str());
    while(std::getline(file, str)){
      while(str.substr(0, 1).find(" ") != std::string::npos){
	str.replace(0, 1, "");
      }

      if(str.find("\r") != std::string::npos) str = str.substr(0, str.find("\r"));

      inStr_p->push_back(str);
    }
    file.close();
  }
  else{
    std::cout << "inFileName, \'" << inFileName << "\' is invalid. Not \'.txt\'. Return 1." << std::endl;
    return 1;
  }

  const int nStr = (int)inStr_p->size();

  for(int iter = 0; iter < nStr; iter++){
    std::string tempStr = inStr_p->at(iter);
    std::string tempStr2 = inStr_p->at(iter);
    tempStr2 = tempStr2.substr(0, tempStr2.find("_2016")) + "_VPt" + tempStr2.substr(tempStr2.find("_2016"), tempStr2.size() - tempStr2.find("_2016"));

    std::string trigStr = tempStr.substr(0, tempStr.find("_2016"));
    std::string dateStr = tempStr.substr(tempStr.find("_2016")+1, tempStr.size() - tempStr.find("_2016")-1);
    dateStr = dateStr.substr(0, dateStr.find(".pdf"));
    dateStr = dateStr.substr(0, 4) + "." + dateStr.substr(4, 2) + "." + dateStr.substr(6, 2);

    std::cout << "\\begin{frame}" << std::endl;
    std::cout << "\\frametitle{\\centerline{" << trigStr << " (" << dateStr << ")}}" << std::endl;
    std::cout << "\\begin{center}" << std::endl;
    std::cout << "\\includegraphics[width=.5\\textwidth]{/Users/cfmcginn/MITHIG/tempPlots2016/July6plots/phoPlots/" << tempStr << "}" << std::endl;
    std::cout << "\\includegraphics[width=.5\\textwidth]{/Users/cfmcginn/MITHIG/tempPlots2016/July6plots/phoPlots/" << tempStr2 << "}" << std::endl;
    std::cout << "\\end{center}" << std::endl;

    std::cout << "\\begin{itemize}" << std::endl;
    std::cout << "\\item{}" << std::endl;
    std::cout << "\\end{itemize}" << std::endl;
    std::cout << "\\end{frame}" << std::endl;

    std::cout << std::endl;
  }

  return 0;
}

int main(int argc, char *argv[])
{
  if(argc != 2){
    std::cout << "Usage: createSlidesFromDirContents.exe <inputFile>" << std::endl;
    std::cout << "Number of args given: " << argc << std::endl;
    for(int iter = 0; iter < argc; iter++){
      std::cout << "  argv[" << iter << "]: " << argv[iter] << std::endl;
    }
    return -1;
  }

  
  int result = createSlidesFromDirContents(argv[1]);

  return result;
}
