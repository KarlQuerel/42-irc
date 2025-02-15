
#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "CommandHandler.hpp"
#include "Server.hpp"
#include "User.hpp"
#include "UserManager.hpp"
#include "IrcReplies.hpp"
#include <iostream>
#include <string>

void	command_kick(
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
	std::string channel_name, nickname;

	if (!(ss >> channel_name >> nickname) || channel_name.empty() || nickname.empty())
	{
		client.write(ERR_NEEDMOREPARAMS(SERVER_NAME, "KICK"));
		return ;
	}

	if (is_kick_valid(_channel_manager, _user_manager, client, channel_name, nickname) == false)
		return ;

	handle_kick_command(_channel_manager, _user_manager, _client_manager, client, channel_name, nickname);

	return ;
}
