
#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "CommandHandler.hpp"
#include "Server.hpp"
#include "User.hpp"
#include "UserManager.hpp"
#include "IrcReplies.hpp"
#include <iostream>
#include <string>

void	handle_topic_command(
	ChannelManager &_channel_manager,
	UserManager &_user_manager,
	Client &client,
	ClientManager &_client_manager,
	std::string const &channel_name,
	std::string const &topic,
	std::string const &args
	)
{
	Channel channel = _channel_manager.get_channel(channel_name);

	User& user = _user_manager.get_user(client.get_fd());
	if (args.empty() == true)
	{
		if (channel.topic.empty() == true)
		{
			client.write(RPL_NOTOPIC(user.get_nickname(), channel_name));
		}
	}
	else
	{
		_channel_manager.set_channel_topic(channel_name, topic);
		
		std::set<int> clients_in_channel = _channel_manager.get_channel(channel_name).clients_fd;
		for (std::set<int>::iterator it = clients_in_channel.begin(); it != clients_in_channel.end(); it++)
		{
			Client curr_client = _client_manager.get_client(*it);
			curr_client.write(RPL_TOPIC(user.get_nickname(), user.get_username(), channel_name, topic, "TOPIC"));
		}
	}
	return ;
}

void	command_topic(
	ChannelManager &_channel_manager,
	UserManager &_user_manager,
	ClientManager &_client_manager,
	const ServerSettings &_server_settings,
	Client &client,
	std::string const &args
	)
{
	(void)_server_settings;

	std::istringstream ss(args);
	std::string channel_name, topic;

	if (!(ss >> channel_name >> topic) || channel_name.empty() || topic.empty())
	{
		client.write(ERR_NEEDMOREPARAMS(SERVER_NAME, "topic"));
		return ;
	}

	if (is_topic_valid(_channel_manager, client, channel_name) == false)
		return ;

	handle_topic_command(_channel_manager, _user_manager, client, _client_manager, channel_name, topic, args);
	return ;
}
