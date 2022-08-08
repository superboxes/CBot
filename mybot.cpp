#include <dpp/dpp.h>

const std::string BOT_TOKEN = "OTc4MzYyMDcyNzUwNDg5Njgw.Gy2Df_.179OxyohpF2B6dTLjIX0PUNkkNivXh4Q8GvTEE";

int main() {
	    dpp::cluster bot(BOT_TOKEN);
	 
	    bot.on_log(dpp::utility::cout_logger());
	 
	    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
	         if (event.command.get_command_name() == "ping") {
	            event.reply("Pong!");
	        }
	    });
	 
	    bot.on_ready([&bot](const dpp::ready_t& event) {
          std::cout << "Bot is ready!" << std::endl;
	        if (dpp::run_once<struct register_bot_commands>()) {
	            bot.global_command_create(
	                dpp::slashcommand("ping", "Ping pong!", bot.me.id)
	            );
	        }
	    });
	 
	    bot.start(dpp::st_wait);
	}
