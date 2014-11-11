(function ($) {
  /**
   * Set a grid on the background of the region with a best effort.
   *
   * Will work with panels in-place-editor and with some region styles.
   */
  Drupal.behaviors.gridBackgound = {
    attach: function (context, settings) {
      var pgsRows = $('.pgs-rows-layout-row .grid-system-row');
      if (pgsRows.length > 0) {
        // Link so the user can opt out of the grid overlay.
        $('.pgs-rows-layout').once().prepend('<div class="overlay-toggler"><a href="#">' + Drupal.t('Toggle grid overlay') + '</a></div>');

        var toggleGrid = function () {
          pgsRows.each(function (index) {
            $(this).toggleClass('grid-system-background-grid');
          });
        };
        // Only show overlay if the cookie to hide it is not there/empty.
        if (!$.cookie('hide-pgs-overlay')) {
          toggleGrid();
        }

        $('.overlay-toggler a').once().click(function() {
          toggleGrid();
          // Also toggle the cookie setting.
          $.cookie('hide-pgs-overlay', ($.cookie('hide-pgs-overlay') ? "" : "yes"), {path: '/'});
        });
      }
    }
  };
})(jQuery);
