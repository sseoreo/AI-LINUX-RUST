#ifndef FILESERVER_H
#define FILESERVER_H

#include <string>
#include <netinet/in.h>
#include <thread>
#include <condition_variable>
#include <mutex>

class FileServer {
public:
    FileServer(bool is_remote);
    ~FileServer();
    void start(const std::string& filename);
    void startInThread(const std::string& filename);
    int getPort() const;
    std::string getIP() const;
    size_t getFileSize(const std::string& filename) const;
    std::mutex mtx;
    std::condition_variable cv;
    bool fileSent;

private:
    int serverSocket;
    int port;
    std::string ip;
    struct sockaddr_in serverAddr;
    std::thread serverThread;

    void sendFile(int clientSocket, const std::string& filename);
    void updateServerInfo();
    void serverTask(const std::string& filename);
};

#endif // FILESERVER_H
