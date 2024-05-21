
#include "ChannelManager.hpp"
#include "ClientManager.hpp"
#include "CommandHandler.hpp"
#include "Server.hpp"
#include "User.hpp"
#include "UserManager.hpp"
#include <iostream>
#include <string>


void	command_auth(
	ChannelManager &_channel_manager,
	UserManager &_user_manager,
	ClientManager &_client_manager,
	const ServerSettings &_server_settings,
	Client &client,
	std::string const &args
	)
{
	(void)args;
	(void)_user_manager;
	(void)_client_manager;
	(void)_server_settings;

	User& user = _user_manager.get_user(client.get_fd());
	user.set_is_authenticated(true);
	_channel_manager.send_message_to_channel2("", BGRN + user.get_nickname() + " has been authenticated\n");
	return ;
}
