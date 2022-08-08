#include <dpp/dpp.h>

const std::string BOT_TOKEN = "YOUR TOKEN HERE";

int main() {
	    dpp::cluster bot(BOT_TOKEN);
	 
	    bot.on_log(dpp::utility::cout_logger());
	 
	    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
	         if (event.command.get_command_name() == "ping") {
	            event.reply("Pong!");
	        }
          if (event.command.get_command_name() == "echo") {
            std::string textToEcho = std::get<std::string>(event.get_parameter("text"));
            event.reply("**" + textToEcho + "**");
          }
	    });
	 
	    bot.on_ready([&bot](const dpp::ready_t& event) {
          std::cout << "Bot is ready!" << std::endl;
              dpp::slashcommand pingCommand("ping", "Pong!", bot.me.id);
              dpp::slashcommand echoCommand("echo", "Echos what you said", bot.me.id);
              echoCommand.add_option(
                  dpp::command_option(dpp::co_string, "text", "The text to echo", true)
              );
              bot.global_command_create(pingCommand);
              bot.global_command_create(echoCommand);
	    });
	 
	    bot.start(dpp::st_wait);
	}
