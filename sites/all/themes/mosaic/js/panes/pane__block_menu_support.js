
// Atlassian issue colloector script that operates on the support menu.

// Requires jQuery!
jQuery.ajax({
  url: "https://coraltech.atlassian.net/s/en_USpfg3b3-1988229788/6095/38/1.4.0-m2/_/download/batch/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector-embededjs/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector-embededjs.js?collectorId=0fcea230",
  type: "get",
  cache: true,
  dataType: "script"
});

window.ATL_JQ_PAGE_PROPS =  {
  "triggerFunction": function(showCollectorDialog) {
  //Requries that jQuery is available! 
  jQuery(".pane-menu-support .issues-tab").click(function(e) {
    e.preventDefault();
    showCollectorDialog();
  });
}};