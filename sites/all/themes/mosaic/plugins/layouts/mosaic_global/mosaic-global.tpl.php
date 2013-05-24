<div class="layout-global page-wrapper">
  <div class="page-inner-wrapper">
    <?php if (!empty($content['header'])): ?>
    <header class="container" role="banner">
      <div class="limiter">
        <?php print render($content['header']); ?>
      </div>
    </header>
    <?php endif; ?>
    <div class="mosaic-cont">
      <?php if (!empty($content['main'])): ?>
      <div class="container main-global clearfix" id="main-content">
        <div class="limiter">
          <?php print render($content['main']); ?>
        </div>
      </div>
      <?php endif; ?>
    </div>
    <?php if (!empty($content['footer'])): ?>
    <footer class="container" role="contentinfo">
      <div class="limiter">
        <?php print render($content['footer']); ?>
      </div>
    </footer>
    <?php endif; ?>
  </div>
</div>
