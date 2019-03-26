#ifndef TICTOC_HPP
#define TICTOC_HPP

#ifdef WITH_TICTOC

#include <sys/time.h>

#include <map>
#include <list>
#include <memory>
#include <tuple>

namespace med {


// Gets current time down to microseconds
struct timeval get_tick() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time;
}

enum TictocType {
    TIC = 0,
    TOC = 1
};

typedef unsigned long line_id;

typedef struct timestamp {
    line_id line;
    struct timeval time;
    enum TictocType type;
} timestamp;


/**
 * Timer
 */
class Timer {
public:
    Timer (std::string filename, bool display = true, int max_hist_length=10000): filename_(filename), display_(display), max_hist_length_(max_hist_length) {}
    void tic(line_id line, struct timeval time) {
        this->time_queue_.push_back({line, time, TIC});
    };
    void toc(line_id line, struct timeval time) {
        if (this->display_) {
            for (auto it = this->time_queue_.rbegin(); it != this->time_queue_.rend(); ++ it) {
                if (it->type == TIC) {
                    auto tic_time = it->time;
                    printf("%s [%5d,%5d]   elapsed: %10.3f s  %10.3f ms  %10d us\n",
                        this->filename_.c_str(), it->line, line,
                        ((time.tv_sec - tic_time.tv_sec) + (time.tv_usec - tic_time.tv_usec) / 1000000.0),
                        ((time.tv_sec - tic_time.tv_sec) * 1000. +  (time.tv_usec - tic_time.tv_usec) / 1000.0),
                        ((time.tv_sec - tic_time.tv_sec) * 1000000 + time.tv_usec - tic_time.tv_usec)
                    );
                    break;
                }
            }
        }
        this->time_queue_.push_back({line, time, TOC});
        while (this->time_queue_.size() > this->max_hist_length_) {
            this->time_queue_.erase(this->time_queue_.begin());
        }
    };
    void tictoc(line_id line, struct timeval time) {
        this->toc(line, time);
        this->tic(line, time);
    };
    void set_display(bool display) {
        this->display_ = display;
    }

public:
    std::string filename_;
    bool display_;
    int max_hist_length_;
    std::list<timestamp> time_queue_;
};


/**
 * Timer manager
 */
class TimerManager {

public:

    static std::map<std::string, std::shared_ptr<Timer> > timer_map;
    
    static void init(std::string filename, bool display=true, int max_hist_length=10000) {
        if (TimerManager::timer_map.find(filename) != TimerManager::timer_map.end()) {
            return;
        }
        TimerManager::timer_map[filename] = std::make_shared<Timer>(filename, display, max_hist_length);
    }

    static void set_display(bool display) {
        for (auto p: TimerManager::timer_map) {
            p.second->set_display(display);
        }
    }

    static void tic(std::string filename, line_id line) {
        auto it = timer_map.find(filename);
        if (it == timer_map.end()) {
            init(filename);
        }
        it->second->tic(line, get_tick());
    }
    static void toc(std::string filename, line_id line) {
        auto it = timer_map.find(filename);
        if (it == timer_map.end()) {
            init(filename);
        }
        it->second->toc(line, get_tick());
    }
    static void tictoc(std::string filename, line_id line) {
        auto it = timer_map.find(filename);
        if (it == timer_map.end()) {
            init(filename);
        }
        it->second->tictoc(line, get_tick());
    }
};

std::map<std::string, std::shared_ptr<Timer> > TimerManager::timer_map;

}

#endif

#ifdef WITH_TICTOC
#define TICTOC_DISPLAY med::TimerManager::set_display(true);
#define TICTOC_NODISPLAY med::TimerManager::set_display(false);
#define TIC med::TimerManager::init(__FILE__);med::TimerManager::tic(__FILE__, __LINE__);
#define TOC med::TimerManager::init(__FILE__);med::TimerManager::toc(__FILE__, __LINE__);
#define TICTOC med::TimerManager::init(__FILE__);med::TimerManager::tictoc(__FILE__, __LINE__);
#else
#define TICTOC_DISPLAY
#define TICTOC_NODISPLAY
#define TIC
#define TOC
#define TICTOC
#endif

#endif