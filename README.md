### notes

to flash your keyboard with this keymap on linux, follow instructions [here](https://docs.qmk.fm/#/getting_started_docker) or just copy & paste the commands below.

get QMK firmware

	git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git && cd qmk_firmware

get keymap and name it as `custom`
	
	git clone https://github.com/villekervinen/qmk-keymap-planck keyboards/planck/keymaps/custom

flash keymap (use `sudo` if you get "cannot open DFU device" error)

	util/docker_build.sh planck/rev6:custom:dfu-util
