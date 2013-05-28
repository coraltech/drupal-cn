<div class="layout-landing-1">
  <div class="inner-wrapper">
    <?php if (!empty($content['leader'])): ?>
    <div class="container grid-24-last leader clear">
      <div class="limiter">
        <?php print render($content['leader']); ?>
      </div>
    </div>
    <?php endif; ?>
    
    <div class='row'>
      <?php if (!empty($content['main'])): ?>
      <div class="container main-content grid-11">
        <div class="limiter">
          <?php print render($content['main']); ?>
        </div>
      </div>
      <?php endif; ?>
      
      <?php if (!empty($content['secondary'])): ?>
      <div class="container secondary-content grid-13-last">
        <div class="limiter">
          <?php print render($content['secondary']); ?>
        </div>
      </div>
      <?php endif; ?>
    </div>
    
    <?php if (!empty($content['follower'])): ?>
    <div class="container grid-24-last follower clear">
      <div class="limiter">
        <?php print render($content['follower']); ?>
      </div>
    </div>
    <?php endif; ?>
  </div>
</div>