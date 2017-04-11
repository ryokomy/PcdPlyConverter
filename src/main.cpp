#include <iostream>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <QApplication>
#include <QFileDialog>
#include <QString>

using namespace std;

int main (int argc, char *argv[])
{
    QApplication a (argc, argv);
    
    pcl::PCDReader pcdreader;
    pcl::PCDWriter pcdwriter;
    pcl::PLYReader plyreader;
    pcl::PLYWriter plywriter;

    //QString q_filename = QFileDialog::getExistingDirectory(Q_NULLPTR,
    //                                                    "Select .pcd or .ply file",
    //                                                    ".");
    QString q_name = QFileDialog::getOpenFileName(Q_NULLPTR,
                                                      "Select .pcd or .ply file",
                                                      ".");
    string name = q_name.toStdString();
    cout << "read: " << name << endl;

    int path_i = name.find_last_of("\\")+1;
    int ext_i = name.find_last_of(".");
    string extname = name.substr(ext_i,name.size()-ext_i);
    string filename = name.substr(path_i,ext_i-path_i);
    
    pcl::PCLPointCloud2 cloud2;

    if(extname == ".pcd")
    {
        int ret = pcdreader.read(name, cloud2);
        if (ret == -1) //* load the file
        {
            PCL_ERROR ("Couldn't read pcd file \n");
            return (-1);
        }
        plywriter.writeASCII(filename+".ply", cloud2);
        cout << "write: " << filename+".ply" << endl;
    }
    
    else if(extname == ".ply")
    {
        int ret = plyreader.read(name, cloud2);
        if (ret == -1) //* load the file
        {
            PCL_ERROR ("Couldn't read ply file \n");
            return (-1);
        }
        pcdwriter.writeASCII(filename+".pcd", cloud2);
        cout << "write: " << filename+".pcd" << endl;
    }
    
    else cout << "please choose .pcd or .ply file" << endl;

    return 0;
}
