#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "CommandHandler.hpp"
#include "Server.hpp"
#include "UserManager.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include "IrcReplies.hpp"

void	command_join(
	ChannelManager &_channel_manager,
	UserManager &_user_manager,
	ClientManager &_client_manager,
	const ServerSettings &_server_settings,
	Client &client,
	std::string const &args
	)
{
	(void)_client_manager;
	(void)_server_settings;

	// TODO KARL ecrire sur tous les users du chan quand un user join le chan
	std::string const & channel_name = args;

	if (is_check_all_channel_valid(channel_name, client, _channel_manager) == false)
		return ;

	User user = _user_manager.get_user(client.get_fd());

	handle_join_command(_channel_manager, user, client, channel_name);

	return ;
}
