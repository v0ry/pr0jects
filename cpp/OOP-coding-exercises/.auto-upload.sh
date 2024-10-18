#!/bin/sh

# This script auto-uploads the users code into "shadow-branches".
# Requires the user to explicitly opt-in or opt-out once.
# The opt-in/opt-out choice may be reset by deleting "~/.auto-upload.conf"


repo_path="$(git rev-parse --show-toplevel)"
repo_url="$(git remote -v | awk '/origin/ { print $2 }' | head -n 1)"
branch="$(git branch --show-current)"
exercise="${PWD#"$repo_path"}"


check_optin() {
	if [ -f ~/.auto-upload.conf ]
	then
		. "$HOME/.auto-upload.conf"
		if [ "$DO_AUTO_UPLOAD" -eq 0 ]
		then
			exit 0
		fi
	else
		printf '[\e[0;36mINFO\e[0m] Auto-upload not configured yet...\n'
		echo 'Die Lehrveranstaltungsleitung in der KU ESP möchte gerne überprüfen, welche freiwilligen Übungsbeispiele den Studierenden besonders helfen und wie groß der Effekt der freiwilligen Übungsbeispiele ist. Auf dieser Analyse (mit anonymisierten Daten) aufbauend möchte die Lehrveranstaltungsleitung das Angebot der freiwilligen Übungsbeispiele verbessern.'
		echo 'Daher wird mein Code bei freiwilligen Übungsbeispielen (nicht jedoch bei Assignments) beim Aufruf von `make test` standardmäßig an Gitlab gesendet.'
		got_answer=0
		while [ $got_answer -ne 1 ]
		do
			echo 'Ich stimme diesem automatischen Upload von Code beim Aufruf von `make test` zu. (Ja/Nein)'
			read answer
			case "$answer" in
				y | Y | yes | Yes | YES | j | J | ja | Ja | JA )
					echo "DO_AUTO_UPLOAD=1" > ~/.auto-upload.conf
					got_answer=1
					;;
				n | N | no | No | NO | nein | Nein | NEIN )
					echo "DO_AUTO_UPLOAD=0" > ~/.auto-upload.conf
					got_answer=1
					;;
				* )
					echo "Bitte antworte mit 'Ja' oder 'Nein'."
					;;
			esac
		done
	fi
}
check_optin


main() {
	# create shadow repo, if it doesn't exist yet
	if [ ! -d ~/.shadow_repo ]
	then
		git clone "$repo_url" ~/.shadow_repo
		cd ~/.shadow_repo/
		git config --local user.name "Auto-Upload Script"
		git config --local user.email "auto-uploader@example.com"
	fi

	# switch to appropriate branch in shadow repo
	cd ~/.shadow_repo
	git checkout "shadow-$branch" || git checkout -b "shadow-$branch"

	# copy over files
	cp -r "$repo_path$exercise"/* "$HOME/.shadow_repo$exercise/"

	# commit changes
	git add '*.h' '*.c'
	git commit -m "AUTOUPLOAD: $exercise"
	git push --set-upstream origin "shadow-$branch"
}
printf '[\e[0;36mINFO\e[0m] Auto-uploading current implementation...\n'
printf '       Remember, you also need to submit your code through git yourself!\n'
main >/dev/null 2>/dev/null
