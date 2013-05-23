<div class="layout-global page-wrapper">
  <div class="page-inner-wrapper">
    <?php if (!empty($content['header'])): ?>
    <header class="container full-width" role="banner">
      <div class="limiter">
        <?php print render($content['header']); ?>
      </div>
    </header>
    <?php endif; ?>
    
    <?php if (!empty($content['main'])): ?>
    <div class="container page" id="main-content">
      <div class="limiter">
        <?php print render($content['main']); ?>
      </div>
    </div>
    <?php endif; ?>
    
    <?php if (!empty($content['footer'])): ?>
    <footer class="container full-width footer" role="contentinfo">
      <div class="limiter">
        <?php print render($content['footer']); ?>
      </div>
    </footer>
    <?php endif; ?>
  </div>
</div>
