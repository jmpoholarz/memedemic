#include "Location.h"
#include <vector>
#include <iostream>
#include <algorithm>

Location::Location() {
	site NINEGAG = {0};
	NINEGAG.id = 0;
	NINEGAG.adjacencies = {1, 2, 15};

	site IFUNNY = {0};
	IFUNNY.id = 1;
	IFUNNY.adjacencies = {0, 15, 16};

	site IMGUR = {0};
	IMGUR.id = 2;
	IMGUR.adjacencies = {0, 3, 4};

	site FOURCHAN = {0};
	FOURCHAN.id = 3;
	FOURCHAN.adjacencies = {2, 4};

	site REDDIT = {0};
	REDDIT.id = 4;
	REDDIT.adjacencies = {3, 2, 7};

	site DISCORD = {0};
	DISCORD.id = 5;
	DISCORD.adjacencies = {7,6};

	site STEAM = {0};
	STEAM.id = 6;
	STEAM.adjacencies = {7,5};
	
	site TWITCH = {0};
	TWITCH.id = 7;
	TWITCH.adjacencies = {8,6,5,4};
	
	site YOUTUBE = {0};
	YOUTUBE.id = 8;
	YOUTUBE.adjacencies = {15,9,7};
	
	site VINE = {0};
	VINE.id = 9;
	VINE.adjacencies = {8,12,13};
	
	site SNAPCHAT = {0};
	SNAPCHAT.id = 10;
	SNAPCHAT.adjacencies = {11,12};
	
	site INSTAGRAM = {0};
	INSTAGRAM.id = 11;
	INSTAGRAM.adjacencies = {12,10};
	
	site PINTEREST = {0};
	PINTEREST.id = 12;
	PINTEREST.adjacencies = {9,11,13,10};
	
	site TWITTER = {0};
	TWITTER.id = 13;
	TWITTER.adjacencies = {14,9,12};
	
	site FACEBOOK = {0};
	FACEBOOK.id = 14;
	FACEBOOK.adjacencies = {15,17,18,19,13};
	
	site BUZZFEED = {0};
	BUZZFEED.id = 15;
	BUZZFEED.adjacencies = {16,1,0,8,14};
	
	site TUMBLR = {0};
	TUMBLR.id = 16;
	TUMBLR.adjacencies = {1,17,15};
	
	site MYSPACE = {0};
	MYSPACE.id = 17;
	MYSPACE.adjacencies = {16,14};
	
	site EMAIL = {0};
	EMAIL.id = 18;
	EMAIL.adjacencies = {14,19};
	
	site WHATSAPP = {0};
	WHATSAPP.id = 19;
	WHATSAPP.adjacencies = {14,18,20,22,23};
	
	site WECHAT = {0};
	WECHAT.id = 20;
	WECHAT.adjacencies = {19,21};
	
	site WEIBO = {0};
	WEIBO.id = 21;
	WEIBO.adjacencies = {20,22};
	
	site QQ = {0};
	QQ.id = 22;
	QQ.adjacencies = {21,20,19,23};
	
	site VK = {0};
	VK.id = 23;
	VK.adjacencies = {22,19};
	
	this->sites.push_back(NINEGAG);
	this->sites.push_back(IFUNNY);
	this->sites.push_back(IMGUR);
	this->sites.push_back(FOURCHAN);
	this->sites.push_back(REDDIT);
	this->sites.push_back(DISCORD);
	this->sites.push_back(STEAM);
	this->sites.push_back(TWITCH);
	this->sites.push_back(YOUTUBE);
	this->sites.push_back(VINE);
	this->sites.push_back(SNAPCHAT);
	this->sites.push_back(INSTAGRAM);
	this->sites.push_back(PINTEREST);
	this->sites.push_back(TWITTER);
	this->sites.push_back(FACEBOOK);
	this->sites.push_back(BUZZFEED);
	this->sites.push_back(TUMBLR);
	this->sites.push_back(MYSPACE);
	this->sites.push_back(EMAIL);
	this->sites.push_back(WHATSAPP);
	this->sites.push_back(WECHAT);
	this->sites.push_back(WEIBO);
	this->sites.push_back(QQ);
	this->sites.push_back(VK);
}

/*
Location::Location(int name) {
	this->name = name;
}*/

std::vector<int> Location::getMemeStatus(int name) {
	std::list<site>::iterator it;
	for (it = this->sites.begin(); it != this->sites.end(); ++it) {
    		if (it->id == name) {
			return it->memeStatus;
		}
	}
	std::vector<int> error = {-1};
	return error;
}
void Location::setMemeStatus(int meme, int level, int name) {
	std::list<site>::iterator it;
	for (it = this->sites.begin(); it != this->sites.end(); ++it) {
    		if (it->id == name) {
			it->memeStatus[meme] = level;
		}
	}
}

bool Location::hasCMCServer(int name) {
	std::list<site>::iterator it;
	for (it = this->sites.begin(); it != this->sites.end(); ++it) {
    		if (it->id == name) {
			return it->CMCServer;
		}
	}
}
void Location::setCMCServer(int name) {
	std::list<site>::iterator it;
	for (it = this->sites.begin(); it != this->sites.end(); ++it) {
    		if (it->id == name) {
			it->CMCServer = true;
		}
	}
}

std::vector<int> Location::getAdjacentLocations(int name) {
	std::list<site>::iterator it;
	for (it = this->sites.begin(); it != this->sites.end(); ++it) {
    		if (it->id == name) {
			return it->adjacencies;
		}
	}
	std::vector<int> error = {-1};
	return error;
}

bool Location::isAdjacent(int current, int location) {
	std::list<site>::iterator it;
	for (it = this->sites.begin(); it != this->sites.end(); ++it){
    	if (it->id == current) {
			if (std::find(it->adjacencies.begin(), it->adjacencies.end(), location) != it->adjacencies.end()) {
				return true;
			} else {
				return false;
			}
		}
	}
}

Location::~Location() {

}
