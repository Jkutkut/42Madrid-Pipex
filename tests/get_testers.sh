#!/bin/sh

main() {
	# Check if root of repository
	if [ ! -d .git ]; then
		echo "This script must be run from the root of the repository"
		return
	fi

	repos="https://github.com/vfurmane/pipex-tester.git https://github.com/ael-bekk/PIPEX_TESTER.git https://github.com/Yoo0lh/pipex_tester_42.git https://github.com/gmarcha/pipexMedic.git"

	for repo in $repos; do
		git clone $repo
	done

	echo "Done"
}

main
