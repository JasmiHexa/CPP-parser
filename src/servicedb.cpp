#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Service class examples that the parser detects
class UserService {
public:
    string getUserDetails(int userId) {
        // Service call pattern: getUserDetails
        return "User details for ID: " + to_string(userId);
    }
    
    bool authenticateUser(string username, string password) {
        // Service call pattern: authenticateUser
        return true;
    }
    
    void createUser(string userData) {
        // Service call pattern: createUser
        cout << "Creating user: " << userData << endl;
    }
};

class DatabaseService {
public:
    bool executeQuery(string query) {
        // Service call pattern: executeQuery
        return true;
    }
    
    void connectDatabase(string connectionString) {
        // Service call pattern: connectDatabase
        cout << "Connecting to database: " << connectionString << endl;
    }
};

class HttpService {
public:
    string sendRequest(string url, string data) {
        // Service call pattern: sendRequest
        return "Response from: " + url;
    }
    
    void receiveResponse(string response) {
        // Service call pattern: receiveResponse
        cout << "Received: " << response << endl;
    }
};

class MessageQueueService {
public:
    void publishMessage(string topic, string message) {
        // Service call pattern: publishMessage
        cout << "Publishing to topic: " << topic << endl;
    }
    
    string subscribeToTopic(string topic) {
        // Service call pattern: subscribeToTopic
        return "Subscribed to: " + topic;
    }
};

// Main application class
class Application {
private:
    UserService userService;
    DatabaseService dbService;
    HttpService httpService;
    MessageQueueService mqService;
    
public:
    void processUserLogin(string username, string password) {
        // Service call detection: userService.authenticateUser()
        bool isAuthenticated = userService.authenticateUser(username, password);
        
        if (isAuthenticated) {
            // Service call detection: userService.getUserDetails()
            string userDetails = userService.getUserDetails(123);
            
            // Service call detection: dbService.executeQuery()
            dbService.executeQuery("SELECT * FROM users WHERE id = 123");
            
            // Service call detection: httpService.sendRequest()
            string response = httpService.sendRequest("https://api.example.com/user", userDetails);
            
            // Service call detection: mqService.publishMessage()
            mqService.publishMessage("user.login", "User logged in successfully");
        }
    }
    
    void createNewUser(string userData) {
        // Service call detection: userService.createUser()
        userService.createUser(userData);
        
        // Service call detection: dbService.connectDatabase()
        dbService.connectDatabase("mysql://localhost:3306/users");
        
        // Service call detection: httpService.receiveResponse()
        httpService.receiveResponse("User created successfully");
    }
    
    void handleMessageQueue() {
        // Service call detection: mqService.subscribeToTopic()
        string subscription = mqService.subscribeToTopic("notifications");
        
        // Service call detection: mqService.publishMessage()
        mqService.publishMessage("system.status", "Service is running");
    }
    
    // HTTP client simulation (detected by parser patterns)
    void makeHttpCall() {
        cout << "Making HTTP call to: https://api.example.com/data" << endl;
        cout << "HTTP call completed successfully" << endl;
    }
    
    // gRPC client simulation (detected by parser patterns)
    void makeGrpcCall() {
        cout << "Making gRPC call to: localhost:50051" << endl;
        cout << "gRPC call completed successfully" << endl;
    }
    
    // Database operations simulation (detected by parser patterns)
    void performDatabaseOperations() {
        cout << "Opening database: test.db" << endl;
        cout << "Executing query: CREATE TABLE users (id INTEGER PRIMARY KEY, name TEXT);" << endl;
        cout << "Database operations completed successfully" << endl;
    }
    
    // Boost.Beast HTTP simulation (detected by parser patterns)
    void makeBoostHttpCall() {
        cout << "Making Boost.Beast HTTP call" << endl;
        cout << "Boost.Beast HTTP call completed successfully" << endl;
    }
    
    // Poco HTTP client simulation (detected by parser patterns)
    void makePocoHttpCall() {
        cout << "Making Poco HTTP call" << endl;
        cout << "Poco HTTP call completed successfully" << endl;
    }
};

// Global service functions (detected by parser patterns)
void logServiceCall(string serviceName, string operation) {
    cout << "Service call: " << serviceName << " -> " << operation << endl;
}

void auditServiceAccess(string userId, string serviceName) {
    cout << "Audit: User " << userId << " accessed " << serviceName << endl;
}

// Main function demonstrating service calls
int main() {
    Application app;
    
    // Service call detection: app.processUserLogin()
    app.processUserLogin("john_doe", "password123");
    
    // Service call detection: app.createNewUser()
    app.createNewUser("{\"name\": \"Jane Doe\", \"email\": \"jane@example.com\"}");
    
    // Service call detection: app.handleMessageQueue()
    app.handleMessageQueue();
    
    // Service call detection: app.makeHttpCall()
    app.makeHttpCall();
    
    // Service call detection: app.makeGrpcCall()
    app.makeGrpcCall();
    
    // Service call detection: app.performDatabaseOperations()
    app.performDatabaseOperations();
    
    // Global service function calls
    logServiceCall("UserService", "authenticateUser");
    auditServiceAccess("john_doe", "DatabaseService");
    
    return 0;
} 