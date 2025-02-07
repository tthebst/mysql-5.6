# Uninstall plugin
let $privacy_plugin_was_early_installed = `SELECT COUNT(*) = 0
FROM mysql.plugin WHERE NAME = 'privacy_plugin'`;
let $sql_privacy_log_was_early_installed = `SELECT COUNT(*) = 0
FROM mysql.plugin WHERE NAME = 'SQL_PRIVACY_LOG'`;

disable_query_log;
disable_warnings;
# $privacy_plugin_was_early_installed = 1 means the privacy plugin was
# installed at the startup time instead of being installed dynamically.
# If so, we don't want to uninstall them.
if (!$privacy_plugin_was_early_installed)
{
  UNINSTALL PLUGIN privacy_plugin;
}
if (!$sql_privacy_log_was_early_installed)
{
  UNINSTALL PLUGIN SQL_PRIVACY_LOG;
}
enable_warnings;
enable_query_log;
