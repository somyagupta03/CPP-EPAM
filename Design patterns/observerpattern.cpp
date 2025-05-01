#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Subscriber;

// Interface (abstract class) for YouTubeChannel
class YouTubeChannel {
public:
    virtual void addSubscriber(std::shared_ptr<Subscriber> subscriber) = 0;
    virtual void removeSubscriber(std::shared_ptr<Subscriber> subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~YouTubeChannel() = default;
};

// Subscriber interface
class Subscriber {
public:
    virtual void update(const std::string& video) = 0;
    virtual ~Subscriber() = default;
};

class YouTubeChannelImpl : public YouTubeChannel {
private:
    std::vector<std::shared_ptr<Subscriber>> subscribers;
    std::string video;

public:
    void addSubscriber(std::shared_ptr<Subscriber> subscriber) override {
        subscribers.push_back(subscriber);
    }

    void removeSubscriber(std::shared_ptr<Subscriber> subscriber) override {
        subscribers.erase(
            std::remove(subscribers.begin(), subscribers.end(), subscriber),
            subscribers.end()
        );
    }

    void notifySubscribers() override {
        for (const auto& subscriber : subscribers) {
            subscriber->update(video);
        }
    }

    void uploadNewVideo(const std::string& newVideo) {
        video = newVideo;
        notifySubscribers();
    }
};

class YouTubeUser : public Subscriber {
private:
    std::string name;

public:
    YouTubeUser(const std::string& name) : name(name) {}

    void update(const std::string& video) override {
        std::cout << name << " received notification about new video: " 
                  << video << std::endl;
    }
};

int main() {
    // Create channel
    YouTubeChannelImpl channel;

    // Create subscribers
    auto user1 = std::make_shared<YouTubeUser>("Alice");
    auto user2 = std::make_shared<YouTubeUser>("Bob");
    auto user3 = std::make_shared<YouTubeUser>("Charlie");

    // Subscribe users
    channel.addSubscriber(user1);
    channel.addSubscriber(user2);
    channel.addSubscriber(user3);

    // Upload video
    channel.uploadNewVideo("C++ Design Patterns Tutorial");

    // Unsubscribe one user
    channel.removeSubscriber(user2);

    // Upload another video
    channel.uploadNewVideo("Observer Pattern in C++");

    return 0;
}